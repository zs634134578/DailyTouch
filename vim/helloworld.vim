python << EOF

function Hello():
	print "hello, world!"
EOF

function! Helloworld()
	python hello()
endfunction

command! -nargs=0 Helloworld call Helloworld()
