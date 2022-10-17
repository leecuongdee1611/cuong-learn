#!/bin/bash
SRC=./backup/
DES=~/.config/nvim/

if [ ! -d "${DES} " ]
then
    echo "*** ${DES} not exist. Creating ..."
	mkdir -p ${DES}
fi

echo "*** Sync files to ~/.config/nvim"
rsync -a ${SRC} ${DES}
tree ${DES} -L 2