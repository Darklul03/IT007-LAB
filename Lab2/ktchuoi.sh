#!/bin/bash

if [ "$#" -ge "3" ] || { echo "Not enough argument supplied (need 3)"; exit 1; }
then
    if [ -f "$2" ]
    then
        if grep -q "$1" "$2"
        then
            echo "Trong tap tin $2 co chuoi \"$1\"" >$3
        else
            echo "Trong tap tin $2 khong co chuoi $1" >$3
        fi

    else
        echo "Tap tin $2 khong ton tai" >$3
    fi
fi
