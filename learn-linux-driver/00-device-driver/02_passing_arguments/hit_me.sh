#!/bin/bash
cd ./source/

KERNEL=passing_arguments

sudo make clean
sudo make all
ls -al
echo ""
echo "*** Loading the kernel"
sudo insmod ${KERNEL}.ko valueETX=14 nameETX="Cuong" arr_valueETX=100,102,104,106
lsmod | grep "${KERNEL}"
dmesg | tail -n 8
echo ""
echo "*** Run callback"
sudo chmod 775 /sys/module/${KERNEL}/parameters/cb_valueETX
sudo sh -c "echo 5 > /sys/module/${KERNEL}/parameters/cb_valueETX"
dmesg | tail -n 2
echo ""
sudo rmmod ${KERNEL}
dmesg | tail -n 1