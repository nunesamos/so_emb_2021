busca_e_conta: main.o find_txt.o
	gcc $(CFLAGS) -o busca_e_conta main.o find_txt.o
main.o: main.c find_txt.h
	gcc $(CFLAGS) -c main.c 
ola.o: find_txt.c find_txt.h
	gcc $(CFLAGS) -c find_txt.c
clean:
	rm -f *.o busca_e_conta