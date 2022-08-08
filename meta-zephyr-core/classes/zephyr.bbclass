inherit terminal
inherit python3native

PYTHONPATH="${STAGING_DIR_HOST}${libdir}/${PYTHON_DIR}/site-packages"

OE_TERMINAL_EXPORTS += "HOST_EXTRACFLAGS HOSTLDFLAGS TERMINFO CROSS_CURSES_LIB CROSS_CURSES_INC"
HOST_EXTRACFLAGS = "${BUILD_CFLAGS} ${BUILD_LDFLAGS}"
HOSTLDFLAGS = "${BUILD_LDFLAGS}"
CROSS_CURSES_LIB = "-lncurses -ltinfo"
CROSS_CURSES_INC = '-DCURSES_LOC="<curses.h>"'
TERMINFO = "${STAGING_DATADIR_NATIVE}/terminfo"

KCONFIG_CONFIG_COMMAND ??= "menuconfig"
ZEPHYR_BOARD ?= "${MACHINE}"

# qemuboot writes into IMGDEPLOYDIR, force to write to DEPLOY_DIR_IMAGE
IMGDEPLOYDIR = "${DEPLOY_DIR_IMAGE}"

python () {
    # Translate MACHINE into Zephyr BOARD
    # Zephyr BOARD is basically our MACHINE, except we must use "-" instead of "_"
    board = d.getVar('ZEPHYR_BOARD', True)
    board = board.replace('-', '_')
    d.setVar('BOARD',board)
}

do_get_zmods() {

    export PYTHONPATH="${RECIPE_SYSROOT_NATIVE}/${libdir}/${PYTHON_DIR}/site-packages:${RECIPE_SYSROOT_NATIVE}/${libdir}/${PYTHON_DIR}"
    cd ${S}
    
    # I really dislike how tied in this is to west, but without reimplementing their script, this seems to be the
    # easiest way to do this
    rm -rf .west; mkdir .west
    cat << EOF >> ${S}/.west/config
[manifest]
path = zephyr
file = west.yml
EOF

    # Get all available modules and add them to ZEPHYR_MODULES
    for i in $(west list|awk 'NR>1 {print $2}'); do
        ZEPHYR_MODULES="${S}/$i\;${ZEPHYR_MODULES}"
    done
    export ZEPHYR_MODULES
}

do_get_zmods[nostamp] = "1"
do_get_zmods[dirs] = "${B}"

EXTRA_OECMAKE:append = " -DZEPHYR_MODULES=${ZEPHYR_MODULES}"

addtask get_zmods after do_patch before do_configure
do_get_zmods[depends] += "west-native:do_populate_sysroot"
do_get_zmods[depends] += "python3-pyyaml-native:do_populate_sysroot"
do_get_zmods[depends] += "python3-pykwalify-native:do_populate_sysroot"
do_get_zmods[depends] += "python3-colorama-native:do_populate_sysroot"
do_get_zmods[depends] += "python3-pyelftools-native:do_populate_sysroot"

python do_menuconfig() {
    os.chdir(d.getVar('ZEPHYR_SRC_DIR', True))
    configdir = d.getVar('ZEPHYR_SRC_DIR', True) + '/outdir/' + d.getVar('BOARD', True)
    try:
        mtime = os.path.getmtime(configdir +"/.config")
    except OSError:
        mtime = 0

    oe_terminal("${SHELL} -c \"ZEPHYR_BASE=%s make BOARD=%s %s; if [ \$? -ne 0 ]; then echo 'Command failed.'; \
                printf 'Press any key to continue... '; \
                read r; fi\"" % (d.getVar('ZEPHYR_BASE', True), d.getVar('BOARD', True),d.getVar('KCONFIG_CONFIG_COMMAND', True)),
                d.getVar('PN', True) + ' Configuration', d)

    try:
        newmtime = os.path.getmtime(configdir +"/.config")
    except OSError:
        newmtime = 0

    if newmtime > mtime:
        bb.warn("Configuration changed, recompile will be forced")
        bb.build.write_taint('do_compile', d)
}
do_menuconfig[depends] += "ncurses-native:do_populate_sysroot"
do_menuconfig[nostamp] = "1"
do_menuconfig[dirs] = "${B}"
addtask menuconfig after do_configure

python do_devshell:prepend () {
    # Most likely we need to manually edit prj.conf...
    os.chdir(d.getVar('ZEPHYR_SRC_DIR', True))
}

