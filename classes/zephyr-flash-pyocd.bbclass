CONNECT_TIMEOUT_SECONDS ?= "30"

python do_flash_usb() {
    try:
        from pyocd.core.helpers import ConnectHelper
        from pyocd.flash.file_programmer import FileProgrammer
    except ImportError:
        bb.fatal("Flashing with pyocd needs the relevant python package. Make sure your host provides it or consult your distribution packages for how to install this prerequisite.")

    timeout = int(d.getVar('CONNECT_TIMEOUT_SECONDS'))
    image = f"{d.getVar('DEPLOY_DIR_IMAGE')}/{d.getVar('PN')}.elf"
    bb.plain(f"Attempting to flash {image} to board {d.getVar('BOARD')}")

    # Try to connect to a probe with a timeout
    now = 0
    step = 3
    while True:
        session = ConnectHelper.session_with_chosen_probe(blocking=False, return_first=True)
        if session:
            break
        if now >= timeout:
            bb.fatal("Timeout while trying to connect to a probe. Make sure the target device is connected and the udev is configured accordingly. See <https://github.com/mbedmicro/pyOCD/tree/master/udev> for help.")
        bb.warn("Can't connect to the probe. Retrying in %d seconds..." % step)
        time.sleep(step)
        now += step

    with session:
        FileProgrammer(session).program(image)
        session.board.target.reset()
}

addtask do_flash_usb after do_deploy

do_flash_usb[nostamp] = "1"
do_flash_usb[vardepsexclude] = "BB_ORIGENV"
