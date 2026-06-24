#!/bin/bash

scripts=[$(ls -1)]  

files=(*)

for file in ${files[@]}; do 
  echo "$file"
done
