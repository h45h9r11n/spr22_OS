#!/bin/bash

# for ((i = -20; i <= 19; i = $i + 3))
# do
# echo $i >> out0.txt
# sudo nice -n $i ./linpack >> out0.txt
# done


for ((i = 2; i <= 32 ; i = $i *2))
do
echo $i >> out.txt
sudo taskset -c 1-$i ./linpack >> out.txt
done

# for ((i = 10; i <= 100 ; i = $i + 10))
# do
# echo $i >> out1.txt
# sudo sysctl kernel.sched_rr_timeslice_ms=$i
# sudo ./linpack >> out1.txt
# done