OBJECT	=queue.o queue_test.o
CC		=gcc
CFLAGS	= -g -c -I. -I..

all:queue

queue:$(OBJECT)
	$(CC) $(OBJECT) -o $@
queue.o:queue.c
	$(CC) $(CFLAGS) $< -o $@
queue_test.o:queue_test.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
disclean:clean
	rm queue
