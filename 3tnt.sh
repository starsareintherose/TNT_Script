#!/bin/bash

# Found TNT

if [ -z "tnt" ]; then
    echo "TNT not found"
    exit 1
fi

# Define input data

input_file=$1

if [ -z "$input_file" ]; then
    echo "Usage: $0 <input_file> <guoyi.run>"
    exit 1
fi

# Define tnt script

script_file=$2

if [ -z "$script_file" ]; then
    echo "Usage: $0 <input_file> <guoyi.run>"
    echo "Warning: guoyi.run will be set as /usr/share/tnt/tnt_scripts/guoyi.run"
    script_file="/usr/share/tnt/tnt_scripts/guoyi.run"
fi


# Define three weighting functions
task1() {
    echo "Equal Weighting started"
    tnt run $script_file $input_file 3 ew 0 str 5 EW,
    echo "Equal Weighting completed"
}

task2() {
    echo "Implied Weighting started"
    tnt run $script_file $input_file 3 iw 12 str 5 IW,
    echo "Implied Weighting completed"
}

task3() {
    echo "Extended Implied Weighting started"
    tnt run $script_file $input_file 3 eiw 12 str 5 EIW,
    echo "Extended Implied Weighting completed"
}

task1 
task2
task3 

echo "All tasks completed"

