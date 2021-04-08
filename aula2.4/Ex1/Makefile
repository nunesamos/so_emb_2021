helloworld: main.o helloworld.o
	gcc $(CFLAGS) -o helloworld main.o helloworld.o
main.o: main.c helloworld.h
	gcc $(CFLAGS) -c main.c 
ola.o: helloworld.c helloworld.h
	gcc $(CFLAGS) -c helloworld.c
clean:
	rm -f *.o helloworld
    