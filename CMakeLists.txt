# cmake primer https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1
cmake_minimum_required(VERSION 3.15~...3.20)

# Optional: The BOARD can be fixed in the CMakeLists.txt file
# This must be done before using find_package for Zephyr. The value is ignored if a "BOARD"
# environment variable is set, and if a build has been performed for a differenet BOARD, then
# changing this variable doesn't help.
# https://docs.zephyrproject.org/latest/develop/application/index.html#application-cmakelists-txt
#
# ATTENTION: `west --build` ignores this variable for the initial build!
# So either use `cmake -B build` (which creates the correct build for BOARD) or specify the
# board for the call to `west`. After the initial build, `west` can figure out the board from
# the CMake cache (or the environment, or the build.board configuration option).
# https://docs.zephyrproject.org/latest/develop/west/build-flash-debug.html#basics
# https://docs.zephyrproject.org/latest/develop/west/build-flash-debug.html#setting-a-default-board
set(BOARD nrf52840dk_nrf52840)
# set(BOARD thingy53_nrf5340)

# Resolve zephyr location using environment variable (see setup.sh)
# https://docs.zephyrproject.org/latest/build/zephyr_cmake_package.html#zephyr-cmake-package-search-order
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(
    EmptyApp
    VERSION 0.1
    DESCRIPTION "Empty application for Nordic Zephyr App"
    LANGUAGES C)

# "app" is defined within the call to "find_package(Zephyr ...)".
# See also, zephyr/cmake/modules/kernel.cmake. We can either define our own application
# or link the "app" target to our own executable, but since there are more dependencies to
# other targets (signing, flashing), it is better to use the zephyr default "app".
target_sources(
    app
    PRIVATE
    src/main.c
)

# target_include_directories(
#     app
#     PRIVATE
# )
