#!/bin/bash

echo "Building and running main application..."
make main
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running program..."
    ./output/main
else
    echo "Compilation failed!"
    exit 1
fi
