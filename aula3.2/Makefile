all: Ex1.out Ex2.out Ex3.out
Ex1.out: Ex1.o gpio_sysfs.o
	gcc Ex1.o gpio_sysfs.o -o Ex1.out
Ex2.out: Ex2.o gpio_dev_mem.o
	gcc Ex2.o gpio_dev_mem.o -o Ex2.out
Ex3.out: Ex3.o gpio_dev_mem.o
	gcc Ex3.o gpio_dev_mem.o -o Ex3.out
Ex1.o: Ex1.c
	gcc -c Ex1.c
Ex2.o: Ex2.c
	gcc -c Ex2.c
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