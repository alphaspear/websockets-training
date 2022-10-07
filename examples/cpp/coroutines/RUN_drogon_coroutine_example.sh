#!/bin/bash  

old_working_dir =  $(pwd)
cd drogon_coroutine_example
mkdir build
cd build
cmake ..
make
./drogon_coroutine_example
cd  $old_working_dir