all: Ex3.out
Ex3.out: Ex3.o gpio_dev_mem.o
	gcc Ex3.o gpio_dev_mem.o -o Ex3.out -lm
Ex3.o: Ex3.c
	gcc -c Ex3.c

gpio_sysfs.o: gpio_sysfs.c
	gcc -c gpio_sysfs.c
gpio_dev_mem.o: gpio_dev_mem.c
	gcc -c gpio_dev_mem.c
blink.o: blink.c blink.h
	gcc $(CFLAGS) -c blink.c

clean:
	rm -f *.out *.o *.bin *.txt *.html