# rp2040-zero-scaffold

This scaffold can be used to create a new RP2040-Zero project. It builds upon normal CMake and `pico-sdk` principles to add decent support for the Waveshare RP2040-Zero.

## Usage

1. Fork / copy this repository to your own
2. Update CMakeLists.txt to have a proper project name
3. `make cmake` or `dockhere make cmake` if you need to run it in a container (for Apple Silicon or similar)
4. `make` or `dockhere make` to build
5. Write the `build/PROJECT_NAME.uf2` file to the RP2040-Zero when it is in `BOOTSEL` mode
6. Connect to the USB serial modem using screen, minicom, etc
