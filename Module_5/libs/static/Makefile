.PHONY: all clean

all: rezultsts

clean:
	rm -rf rezultsts *.o *.a

f1.o: f1.c
	gcc -c f1.c

f2.o: f2.c
	gcc -c f2.c

main.o: main.c
	gcc -c main.c

rezult: main.o f1.o f2.o
	ar rc libfs.a f1.o f2.o
	ranlib libfs.a
	gcc main.o -L. -lfs -o rezultsts
