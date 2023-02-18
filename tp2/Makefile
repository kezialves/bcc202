all: pratica.o ordenacao.o
	@gcc tp.o ordenacao.o -o exe -g -Wall -lm
	@rm -r *.o
pratica.o: tp.c
	@gcc tp.c -c -g -lm
ordenacao.o: ordenacao.c 
	@gcc ordenacao.c -c -g -lm -Wall
run:
	@./exe
