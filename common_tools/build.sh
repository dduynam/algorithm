#!/bin/bash

file_build=$1
file_execute="$(echo ${file_build} | cut -d'.' -f 1).exe"

if [[ $# -eq 0 ]]; then
    echo "No argument provided"
    exit 1
fi

# Execution
echo "g++ ${file_build} -o ${file_execute}  && ./${file_execute}"
g++ ${file_build} -o ${file_execute} && ./${file_execute}