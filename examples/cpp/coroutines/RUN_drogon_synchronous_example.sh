#!/bin/bash  

old_working_dir =  $(pwd)
cd drogon_synchronous_example
mkdir -p build
cd build
cmake ..
make
./drogon_synchronous_example
cd  $old_working_dir