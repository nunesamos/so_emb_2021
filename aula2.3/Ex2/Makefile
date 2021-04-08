mostra: main.o mostra.o
	gcc $(CFLAGS) -o mostra main.o mostra.o
main.o: main.c mostra.h
	gcc $(CFLAGS) -c main.c
mostra.o: mostra.c mostra.h
	gcc $(CFLAGS) -c mostra.c
clean:
	rm -f *.o mostra