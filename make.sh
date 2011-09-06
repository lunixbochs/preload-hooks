#!/bin/bash -u

BASEDIR="$(pwd)/$(dirname $0)"
BASEDIR=$(echo "$BASEDIR" | sed -re 's,/\.,,g')
# main preload object
gcc -g -o bin/preload.so src/preload.c -shared -fPIC -ldl -Isrc/ "-DLIBPATH=\"$BASEDIR/bin/preload.so\""

