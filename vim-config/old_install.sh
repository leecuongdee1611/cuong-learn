#!/bin/bash
echo "Installing NeoVim"
sudo apt install neovim
mkdir ~/.config
cd ~/.config
echo "Download vim plug"
curl -fLo ~/.config/nvim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
# create tree like this
# Link to download config: https://github.com/VuNguyenCoder/VimConfig
# Link tutorial: https://www.youtube.com/watch?v=Tp8i1EHsQ1Q

echo "Download init.vim, ginit.vim, coc-settings.json"
cd ~/.config/nvim
curl -O https://raw.githubusercontent.com/VuNguyenCoder/VimConfig/main/init.vim
curl -O https://raw.githubusercontent.com/VuNguyenCoder/VimConfig/main/ginit.vim
curl -O https://raw.githubusercontent.com/VuNguyenCoder/VimConfig/main/coc-settings.json

echo "Download coc, floaterm, fzf, nerdtree, vimspector"
mkdir settings scripts
cd settings
curl -O https://raw.githubusercontent.com/VuNguyenCoder/VimConfig/main/settings/coc.vim
curl -O https://raw.githubusercontent.com/VuNguyenCoder/VimConfig/main/settings/floaterm.vim
curl -O https://raw.githubusercontent.com/VuNguyenCoder/VimConfig/main/settings/fzf.vim
curl -O https://raw.githubusercontent.com/VuNguyenCoder/VimConfig/main/settings/nerdtree.vim
curl -O https://raw.githubusercontent.com/VuNguyenCoder/VimConfig/main/settings/vimspector.vim

cd ../scripts
curl -O https://raw.githubusercontent.com/VuNguyenCoder/VimConfig/main/scripts/closetag.vim

cd ~
echo "Install some dependencies package"
curl -sL https://deb.nodesource.com/setup_16.x -o nodesource_setup.sh
sudo bash nodesource_setup.sh
sudo apt install nodejs
node -v
sudo apt-get install gcc g++ make
sudo apt-get install python3-dev cmake

echo "Install fonts powerline"
cd ~
# Install fonts
git clone https://github.com/powerline/fonts.git --depth=1
cd fonts
./install.sh
cd ..
rm -rf fonts

cd ~
