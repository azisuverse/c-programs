#!/bin/bash

SRC_DIR="src"
BUILD_DIR="src_build"
BIN_DIR="bin"
TEST_DIR="tests"

mkdir -p "$BUILD_DIR" "$BIN_DIR"

gcc -Wall -c -l "$SRC_DIR/main.c" -o "$BUILD_DIR/main.o"
gcc -Wall -c -l "$SRC_DIR/util.c" -o "$BUILD_DIR/util.o"
gcc -Wall -c -l "$SRC_DIR/calc.c" -o "$BUILD_DIR/calc.o"

gcc "$BUILD_DIR/main.o" "$BUILD_DIR/util.o" "$BUILD_DIR/calc.o" -o "$BIN_DIR/nerd_calc.out"

./bin/nerd_calc.out

