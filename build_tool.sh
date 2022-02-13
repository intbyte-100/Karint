#!/bin/bash

mkdir -p build


_build(){
    cd build
    cmake -G "Unix Makefiles" ..
    make
}

if [ "$1" == 'run' ]; then
    _build
    cd ../res
    ../build/KarintEngine
    ./KarintEngine
elif [ "$1" == "build" ]; then
    _build
    echo resource exporting has finished 
fi



