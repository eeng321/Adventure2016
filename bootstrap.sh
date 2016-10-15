#!/usr/bin/env bash

apt-get update
apt-get install libncurses5-dev
sudo apt-get install -y cmake
sudo apt-get install -y build-essential

cd /vagrant
mkdir build 
cd build 
cmake .. -D CMAKE_INCLUDE_CURRENT_DIR=YES
make 
cd bin/
./rest_server 80

