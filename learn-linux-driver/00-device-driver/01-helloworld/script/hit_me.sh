#!/bin/bash
KERNEL=driver_hello_world

echo "*** Building $KERNEL"
sudo make clean -C ../driver
sudo make all -C ../driver
ls -al ../driver
echo ""

echo "*** Loading kernel $KERNEL"
sudo insmod ../driver/${KERNEL}.ko

lsmod | grep $KERNEL
sudo rmmod $KERNEL