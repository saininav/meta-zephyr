python do_flash_usb() {
    from pyocd.core.helpers import ConnectHelper
    from pyocd.flash.file_programmer import FileProgrammer

    image = f"{d.getVar('DEPLOY_DIR_IMAGE')}/{d.getVar('PN')}.elf"
    bb.plain(f"Attempting to flash {image} to board {d.getVar('BOARD')}")

    with ConnectHelper.session_with_chosen_probe() as session:
        FileProgrammer(session).program(image)
        session.board.target.reset()
}

addtask do_flash_usb after do_deploy

do_flash_usb[nostamp] = "1"
do_flash_usb[vardepsexclude] = "BB_ORIGENV"
