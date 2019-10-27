all: functions.o main.o
	gcc -o program functions.o main.o

functions.o:	functions.c functions.h
	gcc -c -g functions.c

main.o:	main.c functions.h
	gcc -c -g main.c

run:
	./program

clean:
	rm *.o
	rm *~
