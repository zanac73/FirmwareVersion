#!/bin/bash

# -------------------------
#  Global variables
# -------------------------

BOARD_PRO_MINI=arduino:avr:pro
BOARD_UNO=arduino:avr:uno
BOARD_ESP01="esp8266:esp8266:generic"
BOARD_ESP12="esp8266:esp8266:nodemcuv2"
BOARD_ESP32="esp32:esp32:esp32"

BUILD_PATH_ROOT="build"
BUILD_CMD="arduino-cli compile"

# -------------------------
#  Build a .ino
# -------------------------

Build_Ino() {
    local project_folder="$1"
    local board="$2"
    local build_path="../${BUILD_PATH_ROOT}/${project_folder}"
    local ino="${project_folder}.ino"

    # Print project name in cyan color
    echo -e "-- Building project \033[1;36m${project_folder}\033[0m --"

    cd "${project_folder}" || exit

    # Copy compiled binary to build directory
    ${BUILD_CMD} --fqbn ${board} --output-dir . ${ino} &>/dev/null
    if [ $? -ne 0 ]; then
        # print warning in yellow color
        printf "\033[1;33mWarning:\033[0m Build failed for project '${project_folder}'. Skipping.\n"
    fi

    cd .. || exit
}

Build_All() {
    local FQBN="$1"
    echo
    echo "- Building examples for ${FQBN} --"

    # Create build directory if not exists
    # Find all .ino files in subfolders and build them
    find . -name "*.ino" -type f -exec dirname {} \; | while read -r dir; do
        if [ "$dir" != "." ]; then
            Build_Ino "$(basename "$dir")" "${FQBN}"
        fi
    done
}

# -------------------------
#  Main
# -------------------------

echo
echo "---------------------"
echo "  Building examples  "
echo "---------------------"

Build_All "${BOARD_UNO}"
Build_All "${BOARD_ESP12}"

exit $?
