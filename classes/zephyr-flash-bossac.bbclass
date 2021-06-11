#@DESCRIPTION: class file to flash boards like Arduino Nano BLE which depends on bossac for flashing

python do_flash_usb() {
    import shutil
    import subprocess
    import serial.tools.list_ports

    # Note: make sure the installed bossac is set to PATH before running flash_usb()
    # Check if bossac is avaiable for flashing
    origbbenv = d.getVar("BB_ORIGENV", False)
    bossac_path = shutil.which("bossac", path=origbbenv.getVar('PATH'))

    if not bossac_path:
       bb.fatal("ERROR: bossac not found, please install first and add to PATH")

    board = d.getVar('BOARD')

    if board == 'arduino_nano_33_ble':
        # find the serial port to which board is connected to
        for port in serial.tools.list_ports.comports():
            if 'Arduino Nano 33 BLE' in port.description:
                serial_port = port.device
                break
        else:
            bb.fatal("ERROR: board not connected for flashing. Connect via USB and enable permission to connected port")

        image = "%s/%s.bin" % (d.getVar('DEPLOY_DIR_IMAGE'), d.getVar('PN'))

        command = [bossac_path, '-p', serial_port , '-R', '-e', '-w', '-v', '-b', image]
    else:
        bb.fatal("ERROR: Unsupported board %s" % board)

    bb.note("command: %s" % command)
    bb.plain("Attempting to flash board: %s" % board)

    # Random failure are a possibility here, retry till there is a success for finite times
    for _ in range(10, 0, -1):
        try:
            subprocess.check_call(command)
            bb.plain("Bossac Flashing board: %s Success " % board)
            break
        except subprocess.CalledProcessError as e:
            bb.warn("Failed to flash %s (error code: %s). Retrying after 1 second..." % (board, e.returncode))
            time.sleep(1)
}

addtask do_flash_usb after do_deploy

do_flash_usb[nostamp] = "1"
do_flash_usb[vardepsexclude] = "BB_ORIGENV"
