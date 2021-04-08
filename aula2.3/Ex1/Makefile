hello: main.o ola.o
	gcc $(CFLAGS) -o hello main.o ola.o
main.o: main.c ola.h
	gcc $(CFLAGS) -c main.c 
ola.o: ola.c ola.h
	gcc $(CFLAGS) -c ola.c
clean:
	rm -f *.o hello
    