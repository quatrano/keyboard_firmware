# Keyboard Firmware

1. modify the args in `rules.mk`

2. `util/docker_build.sh fingerpunch/ximi:aq`

3. files go to the root dir `fingerpunch_ximi_aq.uf2`

Entrypoint: `keyboards/fingerpunch/ximi/rules.mk`we

Enter boot mode with `hold(q)+b`
    To flash right, leave halves connected. Swap usb-c to the right. Right thinks it's left - use same keycodes to enter boot mode and flash.