#!/bin/bash
echo "Let's start!" > out.txt
echo First stage!
for ((i = -20; i <= 19; i = $i + 3))
do
echo $i
echo $i >> out.txt
sudo nice -n $i ./linpack >> out.txt
done
echo First stage complete!

# for ((i = 2; i <= 32 ; i = $i *2))
# do
# echo $i
# echo $i >> out.txt
# sudo taskset -c 1-$i ./linpack >> out.txt
# done