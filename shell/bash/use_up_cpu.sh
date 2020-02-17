#!/bin/bash

for i in $(seq 1 10)
do
sh -c "while true; do : ; done" &
done
