run: compile
	@./a.out
compile: main.o
	@gcc main.o
main.o: main.c
	@gcc -c main.c
clean:
	@rm -f *.o a.out
