#!/bin/bash
#Alisha Agrawal
#ID: aa3se
#Date: 04/08/2021
#averagetime.sh

echo "enter the exponent for counter.cpp: "
read exponent

if [[ $exponent == "quit" ]] ; then
    exit 0
fi

count=5
total=0

for ((i=1; i<=count; i++))
do

    echo "Running iteration ${i}..."
    time=`./a.out ${exponent}`
    echo "time taken: ${time} ms"
    total=`expr $total + $time`

done

echo "Average time was "`expr $total / $count`"ms"
