set nocompatible
set hlsearch
filetype plugin on
syntax on
set encoding=utf-8
set number
set ts=4
set autoindent
set spelllang=en_us
set relativenumber number
"set pyxversion=3

let python_highlight_all = 1
let g:livepreview_previewer = 'mupdf'
set ut=100
let g:pymode_trim_whitespaces = 1
let g:pymode_options_max_line_length = 200
let g:pymode_options_colorcolumn = 1

"autocomplete
	set wildmode=longest,list,full
	set wildmenu
" deoplete tab-complete
	inoremap <expr><tab> pumvisible() ? "\<c-n>" : "\<tab>"

let g:deoplete#enable_at_startup = 1
if !exists('g:deoplete#omni#input_patterns')
		let g:deoplete#omni#input_patterns = {}
endif 
" omnifuncs
	augroup omnifuncs
			autocmd!
			autocmd Filetype python setlocal omnifunc=pythoncomplete#Complete
	augroup end

	if exists('g:plugs["tern_for_vim"]')
			let g:tern_show_argument_hints = 'on_hold'
			let g:tern_show_signature_in_pum = 1
	endif


inoremap <c-f> <c-x><c-f>
noremap J 5j
noremap K 5k
noremap H ^
noremap L g_
nnoremap ; :

autocmd BufNewFile *.sh :!bash ~/Scripts/template.sh % sh
autocmd BufNewFile *.py :!bash ~/Scripts/template.sh % py
"mkdown
autocmd Filetype rmd map <F5> :!echo<space>"require(rmarkdown);<space>render('<c-r>%')"<space>\|<space>R<space>--vanilla<enter>

"latex
	" word count
	autocmd FileType tex map <F3> :w !detex \| wc -w<CR>
	autocmd FileType tex inoremap <F3> <Esc>:w !detex \| wc -w<CR>
	" template
	autocmd BufNewFile *.tex :!bash ~/Scripts/template.sh % tex
	" binds
	autocmd FileType tex map <F5> :!zathura<space>$(basename<space>%<space>.tex).pdf<space>&<space>detach<CR>
	autocmd FileType tex inoremap <F5> <Esc> :!zathura<space>$(basename<space>%<space>.tex).pdf<space>&<space>detach<CR>
	autocmd FileType tex map <F4> :write ! killall -HUP mupdf<CR>
	autocmd FileType tex inoremap <F4> <Esc> :!killall -HUP mupdf<CR>
	autocmd FileType tex inoremap ;i \textit{}<++><Esc>T{i
	autocmd FileType tex vnoremap ; <ESC>`<i\{<ESC>`>2la}<ESC>?\\{<Enter>a
	autocmd FileType tex inoremap ;sec \section{}<++><Esc>T{i
	autocmd FileType tex inoremap ;ssec \subsection{}<++><Esc>T{i
	autocmd FileType tex inoremap ;sssec \subsubsection{}<++><Esc>T{i
	autocmd FileType tex inoremap ;ol \begin{enumerate}<Enter><Enter>\end{enumerate}<Enter><Enter><++><Esc>3kA\item{}<Esc>i
	autocmd FileType tex inoremap ;ref \autocite{}<++><Esc>T{i
    autocmd FileType tex inoremap ;ul \begin{itemize}<Enter><Enter>\end{itemize}<Enter><Enter><++><Esc>3kA\item{}<Space>
	autocmd FileType tex inoremap ;I \item{}<++><Esc>T{i
	autocmd FileType tex inoremap ;b \textbf{}<++><Esc>T{i
	autocmd FileType tex inoremap ;e \emph{}<++><Esc>T{i
	autocmd FileType tex inoremap ;c \begin{center}<Enter><Enter>\end{center}<Enter><Enter><++><Esc>3ki
	autocmd FileType tex inoremap ;C \begin{columns}<Enter><Enter>\end{columns}<Enter><Enter><++><Esc>3ki
    autocmd FileType tex inoremap ;l \column{.5\textwidth}<Enter>
	autocmd FileType tex inoremap ;f \begin{frame}<Enter><Enter>\end{frame}<Enter><Enter><++><Esc>3ki


inoremap <c-Space> <Esc>/<++><Enter>"_c4l
vnoremap <c-Space> <Esc>/<++><Enter>"_c4l
map <c-Space> <Esc>/<++><Enter>"_c4l
inoremap ;gui <++>

" markdown
	autocmd Filetype markdown map <F4> :!pandoc<space><C-r>%<space>-o<space><C-r>%.pdf<Enter><Enter>
	autocmd Filetype markdown map <F5> :!bash ~/Scripts/mupdf-refresh.sh<space><C-r>%<space>&<space>disown<Enter><Enter>
	autocmd Filetype markdown,rmd inoremap ;b ****<++><Esc>F*hi
	autocmd Filetype markdown,rmd inoremap ;i **<++><Esc>F*i
	autocmd BufNewFile *.md :!bash ~/Scripts/template.sh % md
	autocmd Filetype markdown inoremap ;s ~~<++><Esc>F~i
	autocmd Filetype markdown inoremap ;t <bar><space>*<space><bar><space><++><space><bar><return><bar>----------<bar>----------<bar><return><bar><space><++><space><bar><space><++><space><bar><Esc>2kF*s
	autocmd FileType markdown :call matchadd('ColorColumn', '\%81v', 100)

function! BuildComposer(info)
  if a:info.status != 'unchanged' || a:info.force
    if has('nvim')
      !cargo build --release
    else
      !cargo build --release --no-default-features --features json-rpc
    endif
  endif
endfunction


" python
autocmd Filetype python inoremap def def<space>*(<++>):<Return>'''<Return><++><Return>'''<Return><++><Esc>4kF*s
autocmd Filetype python inoremap while while<space>*:<Esc>F*s
autocmd Filetype python inoremap for for<space>*:<Esc>F*s
highlight ColorColumn ctermbg=magenta

	autocmd FileType python :call matchadd('ColorColumn', '\%81v', 100)
"Setup Plugins
if empty(glob('~/.vim/autoload/plug.vim'))
  silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
    \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
  autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif

call plug#begin('~/.vim/plugged')
"Plug 'vim-syntastic/syntastic'
"Plug 'python-mode/python-mode'
"Plug 'mboughaba/i3config.vim'
Plug 'slashmili/alchemist.vim'
Plug 'zchee/deoplete-clang'
Plug 'godlygeek/tabular'
Plug 'plasticboy/vim-markdown'
Plug 'dylanaraps/wal.vim'
Plug 'Shougo/deoplete.nvim', { 'do': ':UpdateRemotePlugins' }
Plug 'euclio/vim-markdown-composer', { 'do': function('BuildComposer') }
"Plug 'roxma/nvim-yarp'
"Plug 'neovim/neovim'
"Plug 'roxma/vim-hug-neovim-rpc'
"Plug 'neovim/python-client'
Plug 'davidhalter/jedi'
Plug 'zchee/deoplete-jedi'
Plug 'zchee/deoplete-zsh'
Plug 'donRaphaco/neotex', { 'for': 'tex' }
Plug 'ternjs/tern_for_vim', { 'do': 'npm install' }
Plug 'scrooloose/nerdtree'
Plug 'scrooloose/syntastic'
Plug 'lionawurscht/deoplete-biblatex'
Plug 'Shougo/neco-syntax'
Plug 'Shougo/neco-vim'
call plug#end()
colorscheme wal
