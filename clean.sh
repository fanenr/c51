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
)

rm -f ${objs[@]}
