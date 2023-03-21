let g:floaterm_keymap_new    = '<F8>'
let g:floaterm_keymap_prev   = '<F9>'
let g:floaterm_keymap_next   = '<F10>'
let g:floaterm_keymap_toggle = '<F12>'
let g:floaterm_position = 'topright'
let g:floaterm_width = 0.6
let g:floaterm_height = 0.6
let g:floaterm_title = 'Terminal $1/$2'
let g:floaterm_wintype = 'float'
let g:floaterm_rootmarkers = ['.pro']
if has('win32')
  let g:floaterm_shell = 'powershell -nologo'
endif

" Set color
" Set floaterm window's background to black
hi Floaterm guibg=orange
" Set floating window border line color to cyan, and background to orange
hi FloatermBorder guibg=orange guifg=cyan
" Set floaterm window foreground to gray once the cursor moves out from it
hi FloatermNC guifg=gray

autocmd User FloatermOpen        " triggered after opening a new/existed floater

