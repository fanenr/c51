#!/usr/bin/env bash

exts=(
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

rm -f ${exts[@]}
