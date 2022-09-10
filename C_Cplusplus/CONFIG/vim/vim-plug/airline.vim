let g:airline_theme='bubblegum'
let g:airline_powerline_fonts=1

if !exists('g:airline_symbols')
	let g:airline_symbols = {}
endif

"" powerline symbols
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#hunks#enabled=0
let g:airline#extensions#hunks#coc_git = 1
