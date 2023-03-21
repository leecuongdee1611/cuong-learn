"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Plugin list
" (used with Vim-plug - https://github.com/junegunn/vim-plug)
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
call plug#begin(stdpath('config').'/plugged')
" File browser
  Plug 'preservim/nerdTree'                     " File browser  
  Plug 'Xuyuanp/nerdtree-git-plugin'            " Git status
  Plug 'ryanoasis/vim-devicons'                 " Icon
  Plug 'unkiwii/vim-nerdtree-sync'              " Sync current file 

" File search
  Plug 'junegunn/fzf', 
    \ { 'do': { -> fzf#install() } }            " Fuzzy finder 
  Plug 'junegunn/fzf.vim'

" Status bar
  Plug 'vim-airline/vim-airline'
  Plug 'vim-airline/vim-airline-themes'

" Terminal
  Plug 'voldikss/vim-floaterm'                  " Float terminal

" Code syntax highlight
  Plug 'yuezk/vim-js'                           " Javascript
  Plug 'MaxMEllon/vim-jsx-pretty'               " JSX/React
  Plug 'jackguo380/vim-lsp-cxx-highlight'       " C/C++
  Plug 'uiiaoo/java-syntax.vim'                 " Java
  
" Debugging
  "Plug 'puremourning/vimspector'                " Vimspector

" Source code version control 
  Plug 'tpope/vim-fugitive'                     " Git infomation 
  Plug 'tpope/vim-rhubarb' 
  Plug 'airblade/vim-gitgutter'                 " Git show changes 
  Plug 'samoshkin/vim-mergetool'                " Git merge
  
" Code intellisense
	Plug 'jiangmiao/auto-pairs'                   " Parenthesis auto 
	Plug 'neoclide/coc.nvim', {'branch': 'release'}
	
call plug#end()


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Other Settings
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
for setting_file in split(glob(stdpath('config').'/settings/*.vim'))
  execute 'source' setting_file
endfor

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Key mappings
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""" 
" Resize pane
nmap <C-S-Right> :vertical resize -1<CR>    
nmap <C-S-Left> :vertical resize +1<CR>
nmap <C-S-Down> :resize -1<CR>
nmap <C-S-Up> :resize +1<CR>

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => General settings
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set mouse=a                 " Enable mouse
set tabstop=2               " 
set shiftwidth=2            " 
set expandtab
set listchars=tab:\¦\       " Tab charactor 
set list
set foldmethod=syntax       " 
set foldnestmax=1
set foldlevelstart=0        "  
set number                  " Show line number
set ignorecase              " Enable case-sensitive 
syntax on

" Disable backup
set nobackup
set nowb
set noswapfile

" Optimize 
set synmaxcol=200
set lazyredraw
au! BufNewFile,BufRead *.json set foldmethod=indent " Change foldmethod for specific filetype

" Auto reload content changed outside
au CursorHold,CursorHoldI * checktime
au FocusGained,BufEnter * :checktime
autocmd FocusGained,BufEnter,CursorHold,CursorHoldI *
    \ if mode() !~ '\v(c|r.?|!|t)' && getcmdwintype() == ''
      \ | checktime 
    \ | endif
autocmd FileChangedShellPost *
    \ echohl WarningMsg 
    \ | echo "File changed on disk. Buffer reloaded."
    \ | echohl None

" Disable automatic comment in newline
autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o