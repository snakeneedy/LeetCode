#!/usr/bin/env bash

help () {
    echo "Usage:"
    echo "    $0 TARGET"
}
TARGET="$1"

if [[ -z "${TARGET}" ]]; then
    help
    exit
fi

echo "> copying template to '${TARGET}' ..."
if [[ ! -d "${TARGET}" ]]; then
    mkdir "${TARGET}"
fi

cp  "template/LcTemplate.c"    "${TARGET}/Lc${TARGET}.c"
cp  "template/LcTemplate.cpp"  "${TARGET}/Lc${TARGET}.cpp"
cp  "template/LcTemplate.java" "${TARGET}/Lc${TARGET}.java"
cp  "template/LcTemplate.py"   "${TARGET}/Lc${TARGET}.py"
cp  "template/LcTemplate.ts"   "${TARGET}/Lc${TARGET}.ts"

echo "> done!"
