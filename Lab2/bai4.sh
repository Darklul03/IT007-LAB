#!/bin/bash
shopt -s nullglob
if [ "$#" -ne "0" ] || { echo "No string supplied."; exit 1; }
then
    for file in *.txt;
    do
        echo -n "$file: "
        if grep -q "$1" $file
        then
            echo "YES"
        else
            echo "NO"
        fi
    done
fi
