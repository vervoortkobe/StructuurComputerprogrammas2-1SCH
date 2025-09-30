all: circle.o prog.o pi.o
	gcc prog.o circle.o pi.o -o circle

circle.o: circle.c circle.h
	gcc -c circle.c

prog.o: prog.c circle.h
	gcc -c prog.c

pi.o: pi.c circle.h
	gcc -c pi.c