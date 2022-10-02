#!/bin/bash
SRC=./nvim
DES=~/.config/nvim

if [ ! -d "${DES}/settings" ]
then
	echo "*** ${DES} not exist. Creating ..."
	mkdir -p ${DES}/settings
else
	echo "*** Removing old files"
	rm ${DES}/*.vim
	rm ${DES}/*.json
	rm ${DES}/settings/*.vim
fi

echo "*** Copy files to ~/.config/nvim"
cp -R ${SRC}/* ${DES}/
tree ${DES} -L 2
