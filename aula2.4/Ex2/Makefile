ola_usuario_1: main.o escreve_txt.o
	gcc $(CFLAGS) -o ola_usuario_1 main.o escreve_txt.o
main.o: main.c escreve_txt.h
	gcc $(CFLAGS) -c main.c 
ola.o: escreve_txt.c escreve_txt.h
	gcc $(CFLAGS) -c escreve_txt.c
clean:
	rm -f *.o ola_usuario_1