#!/bin/bash

if [ -z $1 ]; then
  echo "Usage : ./login.sh <username>"

else

  case ${1,,} in 
    shishir | admin)
      echo "Hello Exharalted Master,Your puny servant is in your service!"
      ;;

    help)
      echo "Enter your username duffer"
      echo "Usage : ./login.sh <username>"
      ;;

    *)
      echo -e "You are no Master of me.\nFuck Off!!!"

    esac

fi
