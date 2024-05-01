#!/bin/bash

# Replace every [user]
cd /home/[user]
mkdir gsl
cd gsl

wget https://fosszone.csd.auth.gr/gnu/gsl/gsl-2.7.tar.gz
tar -xzvf gsl-2.7.tar.gz

cd gsl-2.7/
./configure --prefix=/home/[user]/gsl/gsl-install
make
# make check # Tests
make install

cd ../../
echo "export LD_LIBRARY_PATH=/home/[user]/gsl/gsl-install/lib" >> .bashrc
