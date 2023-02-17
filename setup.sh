#!/bin/sh

ncs_install=/opt/nordic/ncs
ncs_version=2.2.0

export PATH=$ncs_install/toolchains/v$ncs_version/bin:$PATH
export ZEPHYR_SDK_INSTALL_DIR=$ncs_install/toolchains/v$ncs_version/opt/zephyr-sdk
source $ncs_install/v$ncs_version/zephyr/zephyr-env.sh
west zephyr-export
