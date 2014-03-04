OBJECT	=stack_mem.o stack_test.o
CC		=gcc
CFLAGS	= -g -c -I. -I../..

all:stack

stack:$(OBJECT)
	$(CC) $(OBJECT) -o $@
stack_mem.o:stack_mem.c
	$(CC) $(CFLAGS) $< -o $@
stack_test.o:stack_test.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
disclean:clean
	rm *.exe
