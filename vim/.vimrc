set nocompatible

" change the default .vim directory to user-specific directory where .vimrc is resident.
" 1. set default 'runtimepath' (without ~/.vim folders)
let &runtimepath = printf('%s/vimfiles,%s,%s/vimfiles/after', $VIM, $VIMRUNTIME, $VIM)
" 2. what is the name of the directory containing this file?
let s:portable = expand('<sfile>:p:h')
" 3. add the directory to 'runtimepath'
let &runtimepath = printf('%s,%s,%s/after', s:portable, &runtimepath, s:portable)

"set number	"display line number
filetype plugin indent on	"check file type
set completeopt=longest,menu
syntax on	"syntax highlight
set number
set autoindent
set smartindent
set tabstop=4
set shiftwidth=4
set showmatch
set guioptions-=T
set ruler
set incsearch
set hlsearch
set cursorline
"set foldmethod=syntax
"配色方案, 位于vim/vim70/colors中
colorscheme torte
" show incomplete command
set showcmd
" allow backspacing over everything in insert mode
set backspace=indent,eol,start

"useful vim settings for python
set smarttab		" <abbr. sta>
set expandtab		" 扩展tab为空格 <abbr. et>

" vim 打开文件时以此选项指定的顺序识别文件编码
set fileencodings=ucs-bom,utf-8,cp936   
set fileencoding=utf-8

" 一键切换.h和.cpp
map <F2> :e %:p:s,.h$,.X123X,:s,.cpp$,.h,:s,.X123X$,.cpp,<CR>

" When editing a file, always jump to the last known cursor position.
if has("autocmd")
  autocmd BufReadPost *
        \ if line("'\"") > 0 && line("'\"") <= line("$") |
        \   exe "normal! g`\"" |
        \ endif
endif " has("autocmd")

" for taglist
nnoremap <silent> <F5> :TlistToggle<CR>
" 当仅剩下 Tlist 窗口存在时，退出 vim
let Tlist_Exit_OnlyWindow = 1
" 即使 taglist 窗口关闭时，依然处理文件，即随时更新 tag
let Tlist_Process_File_Always = 1
" 仅仅显示 current active buffer 的 tag
let Tlist_Show_One_File = 1
" GUI Vim 下以 popup menu 的方式显示当前 buffer 中的 tag
let Tlist_Show_Menu = 1
" for nesC
let tlist_ncc_settings = 'ncc;g:g_config;c:config;b:g_module;m:module;p:component;i:interface;a:alias'
let Tlist_Use_Right_Window = 1
let Tlist_Compact_Format = 1
"auto open when open vim 
let Tlist_Auto_Open=0

" auto close options when exiting insert mode or moving away
autocmd CursorMovedI * if pumvisible() == 0|pclose|endif
autocmd InsertLeave * if pumvisible() == 0|pclose|endif
set completeopt=menu,menuone

" -- ctags --
set tags=tags;
set autochdir


set nocompatible
filetype off
set rtp+=~/zhousu/tool/.vim/bundle/Vundle.vim
call vundle#begin("~/zhousu/tool/.vim/bundle")
Plugin 'gmarik/Vundle.vim'
Plugin 'bling/vim-airline'
call vundle#end()
filetype plugin indent on


let mapleader=","
let g:mapleader=","



"doxygen toolkit 
let g:DoxygenToolkit_briefTag_pre="@brief "
let g:DoxygenToolkit_paramTag_pre="@param "
let g:DoxygenToolkit_returnTag="@returns   "
"let g:DoxygenToolkit_blockHeader="--------------------------------------------------------------------------"
"let g:DoxygenToolkit_blockFooter="----------------------------------------------------------------------------"
let g:DoxygenToolkit_authorName="zhousu.zs"
let g:DoxygenToolkit_licenseTag="GPL 2.0"

let g:DoxygenToolkit_authorName="zhousu.zs, zhousu.zs@alibaba-inc.com"
let s:licenseTag = "Copyright(C)\<enter>"
let s:licenseTag = s:licenseTag . "For free\<enter>"
let s:licenseTag = s:licenseTag . "All right reserved\<enter>"
let g:DoxygenToolkit_licenseTag = s:licenseTag
let g:DoxygenToolkit_briefTag_funcName="yes"
let g:doxygen_enhanced_color=1


"airline config

"1 tabline config
set laststatus=2
"let g:airline_theme="luna" 

let g:airline_powerline_fonts = 1   
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#buffer_nr_show = 1
nnoremap <C-N> :bn<CR>
nnoremap <C-P> :bp<CR>
"let g:airline#extensions#whitespace#enabled = 0
"let g:airline#extensions#whitespace#symbol = '!'
