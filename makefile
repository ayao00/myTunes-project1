all: linkedlist.o library.o main.o
	gcc -o program linkedlist.o library.o main.o
linkedlist.o: linkedlist.c linkedlist.h
	gcc -c -g linkedlist.c
library.o: library.c library.h
	gcc -c -g library.c
main.o: main.c linkedlist.h library.h
	gcc -c -g main.c
run:
	./program
clean:
	rm *o
	rm *~
