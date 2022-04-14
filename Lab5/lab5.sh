#!/bin/bash

#Создаем тестовый файл
sudo dd if=/dev/zero of=/home/hanhnguyen26/testfile bs=1M count=256 

for T in "ext4" "ntfs"; do
    echo $T 
    mkdir $T
    sudo dd if=/dev/zero of=$T.bin bs=1M count=512 &> /dev/null
    sudo mkfs -t $T -F $T.bin &> /dev/null
    sudo mount $T.bin $T &> /dev/null
    # sudo /usr/bin/time -p cp /home/hanhnguyen26/testfile $T 
    # sudo /usr/bin/time -p cat $T/testfile 
    # sudo /usr/bin/time -p rm $T/testfile 
    sudo iozone -a ./$T -b speedtest.xls
    sudo umount $T
    sudo rm $T*
done

for T in "btrfs" "reiserfs"; do
    echo $T 
    mkdir $T
    sudo dd if=/dev/zero of=$T.bin bs=1M count=512
    sudo mkfs -t $T -f $T.bin 
    sudo mount $T.bin $T 
    # sudo /usr/bin/time -p cp /home/hanhnguyen26/testfile $T 
    # sudo /usr/bin/time -p cat $T/testfile 
    # sudo /usr/bin/time -p rm $T/testfile 
    sudo iozone -a -b speedtest.xls ./$T
    sudo umount $T
    sudo rm $T*
done

