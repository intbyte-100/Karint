#!/bin/bash

cp -r res ../build-lite_engine-Desktop-Debug

if [ "$1" == 'run' ]; then
    cd ../build-lite_engine-Desktop-Debug
    cmake -G "Unix Makefiles" ../lite_engine
    make
    ./LiteEngine
fi



