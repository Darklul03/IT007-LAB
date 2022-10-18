#!/bin/bash

DNUM=(0 31 28 31 30 31 30 31 31 30 31 30 31);

if [ "$#" -ge "3" ] || { echo "Not enough argument supplied (need 3)"; exit 1; }
then
    if [ "$1" -le 1900 ]
    then
        echo "Nam khong hop le" >$3
    elif [ "$2" -gt 12 ] || [ "$2" -lt 1 ]
    then
        echo "Thang khong hop le" >$3
    else
        res=${DNUM[$2]}
        if ([ $(($1 % 4)) -eq 0 ]  && [ $(($1 % 100)) -eq 0 ]) || [ $(($1 % 400)) -eq 0 ]
        then
            res=$(($res+1))
        fi
        echo $res >$3
    fi
fi
