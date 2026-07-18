#!/bin/bash

if [ -z $1 ]; then
  echo "Usage ./ifelif.sh <username>"

elif [ "${1,,}" = "shishir" ]; then 
  echo "Hello Boss!What are the great master $1 orders"

elif [ "${1,,}" = "help" ]; then 
  echo "Just type the username dhakkan"

else
  echo "This is available for my master only"
fi
