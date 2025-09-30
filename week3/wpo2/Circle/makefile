all: circle.o prog.o pi.o
	gcc circle.o prog.o pi.o -o prog

circle.o: circle.c circle.h pi.h
	gcc circle.c -c circle.c

prog.o: prog.c circle.h pi.h
	gcc prog.c -c prog.c

pi.o: pi.c circle.h pi.h
	gcc pi.c -c pi.c