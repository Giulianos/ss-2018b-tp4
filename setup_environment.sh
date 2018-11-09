#!/bin/bash
mkdir params
mkdir ovito_out
mkdir distance_out
sudo apt update
wait;
sudo apt install gcc parallel cmake -y
wait;
./params_generator.sh
./compile.sh
wait;