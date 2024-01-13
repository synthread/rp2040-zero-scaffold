# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Use our pico-sdk submodule
set (PICO_SDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/pico-sdk/)

# Use the custom board definition file
set(PICO_BOARD_HEADER_DIRS ${CMAKE_CURRENT_LIST_DIR} )
set (PICO_BOARD rp2040-zero-board)

# Include build functions from Pico SDK
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set name of project (as PROJECT_NAME) and C/C   standards
project(rp2040-zero-scaffold C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

# Tell CMake where to find the executable source file
add_executable(${PROJECT_NAME}
    main.c
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

pico_generate_pio_header(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/ws2812.pio)

target_sources(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ws2812.c
    ${CMAKE_CURRENT_SOURCE_DIR}/usb.c
)

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    hardware_pio
    hardware_clocks
)

# Enable usb output, disable uart output
pico_enable_stdio_usb(${PROJECT_NAME} ENABLED)
pico_enable_stdio_uart(${PROJECT_NAME} 0)
