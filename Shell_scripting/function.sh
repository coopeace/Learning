#!/bin/bash

showuptime(){
  local up=$(uptime -p | cut -c4-)
  local since=$(uptime -s)
  cat << EOF 
-------
Workstation has been up for ${up}
Up since ${since}
-------
EOF
}

showuptime 

# $( ) — Command substitution
#
# name="Shishir"
#
# echo "${name}123"
# result >> Shishir123
#
# echo "$name123"
# result >> search variable named name123
