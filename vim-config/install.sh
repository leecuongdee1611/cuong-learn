echo "Installing dependencies"
sudo apt update -y
sudo apt upgrade -y
sudo apt install curl

echo "Installing NeoVim"
sudo apt install -y neovim

echo "Create workspace folder"
mkdir -p ~/.config/nvim/

echo "Installing the Vim-plug Plugin Manager"
cd ~/.config/nvim/
curl -fLo ~/.config/nvim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

echo "Installing NodeJS"
curl -sL https://deb.nodesource.com/setup_16.x -o /tmp/nodesource_setup.sh
# nano /tmp/nodesource_setup.sh
sudo bash /tmp/nodesource_setup.sh
sudo apt install nodejs
node -v