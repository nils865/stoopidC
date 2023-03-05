python = python3

compile:
	${python} scripts/compile.py smart gcc

compile-all:
	${python} scripts/compile.py all gcc

run:
	build/stoopid stpd/test.stpd
