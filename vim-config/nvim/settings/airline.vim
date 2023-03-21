let g:airline_powerline_fonts = 1                       " Enable font for status bar

" TABLINE
let g:airline#extensions#tabline#enabled = 1            " Enable Tab bar
let g:airline#extensions#tabline#left_sep = ' '         " Enable Tab seperator 
let g:airline#extensions#tabline#left_alt_sep = '|'     " Enable Tab seperator
let g:airline#extensions#tabline#formatter = 'default'
let g:airline#extensions#tabline#fnamemod = ':t'        " Set Tab name as file name
let g:airline#extensions#tabline#show_close_button = 1 	" remove 'X' at the end of the tabline      
let g:airline#extensions#tabline#show_buffers = 0      	" Dont show buffers in the tabline   
let g:airline#extensions#tabline#tabs_label = 'NIGHTMARE' " can put text here like TABS to denote tab (I clear it so nothing is shown) 

let g:airline#extensions#whitespace#enabled = 0         " Remove warning whitespace"

let g:airline_section_error=''