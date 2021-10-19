#!/bin/bash
# Name: Alisha Agrawal
# Date: 03/30/2021
# ID: aa3se
# averagetime.sh

read dict
read grid

TIME=`./a.out $dict $grid | tail -1`
sum=$TIME
TIME=`./a.out $dict $grid | tail -1`
sum=$((sum+TIME))
TIME=`./a.out $dict $grid | tail -1`
sum=$((sum+TIME))
TIME=`./a.out $dict $grid | tail -1`
sum=$((sum+TIME))
TIME=`./a.out $dict $grid | tail -1`
sum=$((sum+TIME))

echo $((sum/5))
