OBJECT	=vector.o vector_test.o
CC		=gcc
CFLAGS	= -g -c -I. -I..

all:vector

vector:$(OBJECT)
	$(CC) $(OBJECT) -o $@
vector.o:vector.c
	$(CC) $(CFLAGS) $< -o $@
vector_test.o:vector_test.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
disclean:clean
	rm vector
