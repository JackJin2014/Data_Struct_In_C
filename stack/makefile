OBJECT	=stack.o stack_test.o
CC		=gcc
CFLAGS	= -g -c -I. -I..

all:stack

stack:$(OBJECT)
	$(CC) $(OBJECT) -o $@
stack.o:stack.c
	$(CC) $(CFLAGS) $< -o $@
stack_test.o:stack_test.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
disclean:clean
	rm *.exe
