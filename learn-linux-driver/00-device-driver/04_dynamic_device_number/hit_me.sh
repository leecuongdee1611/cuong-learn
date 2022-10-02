#!/bin/bash
cd ./source/
KERNEL=dynamic_alloc
sudo make clean
sudo make all
ls -al
echo ""
echo "*** Load the kernel"
sudo insmod ${KERNEL}.ko
lsmod | grep "${KERNEL}"
dmesg | tail -n 2
cat /proc/devices
echo "*** Unload the kernel"
sudo rmmod ${KERNEL}
dmesg | tail -n 1