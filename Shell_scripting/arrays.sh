#!/bin/bash

characters=("rachel" "ross" "chandler" "phoebey" "joey" "monica")

for character in ${characters[@]}; do
  echo "$character"
done

echo -e "\n"

echo -e "Number of characters:${#characters[@]} \n" # Use "#" for the Number of elements

for i in ${!characters[@]}; do # Use "!" for the Number of elements , result = 0 1 2
  echo "$((i+1)) : ${characters[i]}" # Arthmetic requires "(())"
done

echo -e "\n"
