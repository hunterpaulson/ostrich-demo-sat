#!/bin/sh
DIRNAME="`dirname $0`"
# Set BUILD_ROOT if unset or "" set the BUILD_ROOT to be the above dir
if [ -z ${BUILD_ROOT} ]
then
    export BUILD_ROOT="`cd ${DIRNAME}/../..; pwd`"
fi
echo "BUILD_ROOT is: ${BUILD_ROOT}"

${BUILD_ROOT}/Gds/bin/tkgui/run_seqgen.sh -g ${BUILD_ROOT}/RobotArm/py_dict "$@"
