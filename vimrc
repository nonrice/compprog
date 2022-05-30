filetype plugin indent on 

au filetype cpp nnoremap <F5> <Cmd>:w<CR>:!clear && if clang++ % 
    \ -std=c++17 -Wall -Wextra -fsanitize=address -fsanitize=undefined -g; then
    \ ./a.out < ~/.in; rm a.out && rm -r a.out.dSYM; fi
\<CR>
nnoremap <F6> <Cmd>:e ~/.in<CR>

set ts=4 sw=4 sts=4 ai et
set bs=indent,eol,start
set nu rnu
set sc
set is

call plug#begin()
    Plug 'bfrg/vim-cpp-modern'
    Plug 'cohama/lexima.vim'
call plug#end()

syn on
