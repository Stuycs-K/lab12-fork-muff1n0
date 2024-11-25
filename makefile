run: compile
	./a.out
compile: main.o
	gcc main.o
main.o: main.c
	gcc -o main.c
clean:
	rm -f *.o a.out
