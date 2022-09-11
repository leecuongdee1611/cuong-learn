"" Hiện file ẩn
let NERDTreeShowHidden=1

autocmd VimEnter * NERDTree | wincmd p
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * NERDTree | if argc() > 0 || exists("s:std_in") | wincmd p | endif

"" Mở cùng NERDTree cho tab mới, mặc định là mỗi tab sẽ mở 1 cái mới
autocmd BufWinEnter * silent NERDTreeMirror

"" Tự đóng NERDTree khi đóng tab, mặc định giữ lại NERDTree
autocmd BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() | quit | endif
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") 
      \ && b:NERDTree.isTabTree()) | q | endif

"" Tìm file đang mở trong thư mục bên NERDTree (mặc định không sync với nhau)
map <leader>r :NERDTreeFind<cr>
