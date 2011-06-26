#!/bin/bash -u

# main preload object
gcc -g -o bin/preload.so src/preload.c -shared -fPIC -ldl -Isrc/

