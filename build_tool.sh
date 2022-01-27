#!/bin/bash

mkdir -p build

_exportRes(){
    cp -r res build
}
_build(){
    _exportRes
    cd build
    cmake -G "Unix Makefiles" ..
    make
}

if [ "$1" == 'run' ]; then
    _build
    ./karintEngine
elif [ "$1" == "build" ]; then
    _build
elif [ "$1" == "export_res" ]; then
    _exportRes
    echo resource exporting has finished 
fi



