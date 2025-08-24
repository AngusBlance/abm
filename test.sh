#!/bin/bash

echo "Building and running test application..."
make test
if [ $? -eq 0 ]; then
    echo "Test compilation successful. Running test..."
    ./output/arrest_test
else
    echo "Test compilation failed!"
    exit 1
fi 