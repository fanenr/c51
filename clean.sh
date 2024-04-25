#!/usr/bin/env bash

objs=(
  **/*.lk
  **/*.lst
  **/*.map
  **/*.mem
  **/*.rst
  **/*.sym
  **/*.asm
  **/*.rel
  **/*.ihx
  **/*.adb
  **/*.cdb
  **/*.omf
)

rm -f ${objs[@]}
