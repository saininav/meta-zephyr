
python zephyrtest_virtclass_handler () {
    cls = e.data.getVar("BBEXTENDCURR", True)
    variant = e.data.getVar("BBEXTENDVARIANT", True)

    # ipk doesn't like underscores in pacakges names. So just use dashes
    # for PN and the image name.
    variant_dashes = variant.replace('_', '-')

    pn = e.data.getVar("PN", True) + "-" + variant_dashes
    pn_underscores = e.data.getVar("PN", True) + "-" + variant

    e.data.setVar("PN", pn)
    e.data.setVar("ZEPHYR_IMAGENAME", "test_" + variant_dashes + ".elf")

    # Most tests for Zephyr 1.6 are in the "legacy" folder
    e.data.setVar("ZEPHYR_IMAGE_SRCDIR", "tests/legacy/kernel/" + variant)
    e.data.setVar("ZEPHYR_MAKE_OUTPUT", "zephyr.elf")

    # Allow to build using both foo-some_test form as well ass foo-some-test
    e.data.setVar("PROVIDES", e.data.getVar("PROVIDES", True) + pn_underscores)
}

addhandler zephyrtest_virtclass_handler
zephyrtest_virtclass_handler[eventmask] = "bb.event.RecipePreFinalise"
