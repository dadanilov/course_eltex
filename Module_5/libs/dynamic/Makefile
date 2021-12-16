.PHONY: all clean

all: rezultdyn

clean:
	rm -rf rezultdyn *.o *.so

f1.o: f1.c
	gcc -fPIC -c f1.c

f2.o: f2.c
	gcc -fPIC -c f2.c

libfsdyn.so: f1.o f2.o
	gcc -shared -o libfsdyn.so f1.o f2.o

main.o: main.c
	gcc -c main.c

rezultdyn: main.o libfsdyn.so
	gcc main.o -L. -lfsdyn -o rezultdyn
