#!/bin/bash
echo "Nhap ten"
read TEN
echo "Nhap MSSV"
read MSSV
until [ $MSSV -eq 21521050 ]
do
    echo "MSSV khong trung. Vui long nhap lai."
    read MSSV
done

echo "Ten: $TEN, MSSV: $MSSV"
