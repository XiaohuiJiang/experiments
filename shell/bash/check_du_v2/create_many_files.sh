#!/bin/bash

function usage(){
  echo "need only 2 parameters:"
  echo "$0 <number_of_files> <under_this_dir>"
  exit 1
}

[[ $# == 2 ]] || usage

[ -e "$2" ] || mkdir -p $2;
[ -d "$2" ] || { echo "Error: $2 is not a regular dir"; exit 1;}

time=`date +%s`
random=`echo $RANDOM`
echo $time $1 $random
for((i=1; i<=$1; i++)); do
        touch "$2/$time-$i-$random"
done
