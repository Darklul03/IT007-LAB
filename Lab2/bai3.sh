#!/bin/bash
echo "Nhap n"
read N
until [ $N -lt 10 ] && [ $N -gt 0 ]
do
    echo "Vui long nhap so duong be hon 10"
    read N
done

SUM=0
for ((i=1; i<=$N; i++))
do
    SUM=$(($SUM+$i))
done

echo "Tong cac so den $N la: $SUM"
