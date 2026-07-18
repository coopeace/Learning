#!/bin/bash

# enumerate(){
#   if [ -z $1 ];then 
#     echo "usage: enumerate <variable>"
#     return 1
#   fi
#
#   local var="$1[@]"
#
#   echo "${!var}"
#
#   # for i in "${!var}";do
#   #   echo "$i. ${!var}"
#   # done
# }
#
# characters=("rachel" "ross" "chandler" "phoebey" "joey" "monica")
# enumerate characters

#!/bin/bash

# Function expects the elements to be passed as separate arguments
enumerate() {
    # This takes all arguments passed to the function 
    # and puts them into a new local array called 'local_arr'
    local local_arr=("$@")

    for i in "${!local_arr[@]}"; do
        echo "$i. ${local_arr[$i]}"
    done
}

characters=("rachel" "ross" "chandler" "phoebey" "joey" "monica")

# Use "${characters[@]}" to expand the array into individual words
enumerate "${characters[@]}"
