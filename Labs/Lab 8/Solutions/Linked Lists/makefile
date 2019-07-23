main: main.o list.o
	gcc -g -o main main.o list.o
main.o: main.c
	gcc -g -c main.c
list.o: list.c list.h
	gcc -g -c list.c
clean:
	rm -r -f main *.o *~