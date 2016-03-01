CC = gcc
OBJECTS = test.o main.o selsort.o mergesort.o qsort.o
CFLAGS = -std=c99 -pg -O2 -g -lc
output = test

test: $(OBJECTS)
	$(CC) $(CFLAGS) -o$(output) $(OBJECTS)

test.o:
main.o:
selsort.o:
mergesort.o:
qsort.o:

clean:
	rm -f $(output) *.o
