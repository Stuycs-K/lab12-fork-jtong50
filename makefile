compile: fork.o
	@gcc -o program fork.o
fork.o: fork.c
	@gcc -c fork.c
run: program
	@./program
clean:
	rm *o
	rm program
