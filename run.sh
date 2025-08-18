#!/bin/bash

# Name of the output executable
OUT="program"

# Compile all .c files in the current directory
gcc -std=c11 *.c -o $OUT

# Check if compilation succeeded
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running $OUT..."
    ./$OUT
else
    echo "Compilation failed."
fi
