python = python3
compiler = gcc

compile:
	${python} scripts/compile.py smart gcc

compile-all:
	${python} scripts/compile.py all gcc

analyze:
	${compiler} -o build/stoopid bin/*.o -fsanitize=address
	make run

run:
	build/stoopid stpd/test.stpd
