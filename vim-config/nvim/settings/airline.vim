let g:airline_powerline_fonts = 1                       " Enable font for status bar

" TABLINE
let g:airline#extensions#tabline#enabled = 1            " Enable Tab bar
let g:airline#extensions#tabline#left_sep = ' '         " Enable Tab seperator 
let g:airline#extensions#tabline#left_alt_sep = '|'     " Enable Tab seperator
let g:airline#extensions#tabline#formatter = 'default'
let g:airline#extensions#tabline#fnamemod = ':t'        " Set Tab name as file name
let g:airline#extensions#tabline#show_close_button = 1 	" Remove 'X' at the end of the tabline
let g:airline#extensions#tabline#tabs_label = 'CUONG.LE-HUNG'       " Can put text here like TABS to denote tabs
let g:airline#extensions#tabline#show_tab_type = 0     	" Disables the weird ornage arrow on the tabline
let g:airline#extensions#tabline#show_buffers = 0      	" Dont show buffers in the tabline     
let g:airline#extensions#tabline#show_splits = 0       	" Disables the buffer name that displays on the right of the tabline  
let g:airline#extensions#tabline#show_tab_nr = 0       	" Disable tab numbers  

" Others
let g:airline#extensions#whitespace#enabled = 0         " Remove warning whitespace"
let g:airline_section_error=''
