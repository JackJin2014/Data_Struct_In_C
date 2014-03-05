OBJECT	=queue.o queue_test.o
CC		=gcc
CFLAGS	= -g -c -I. -I..
STD = -std=c99
TARGET = queue_test
OUT = queue

DEPS = queue.h

all : $(TARGET)
$(TARGET): $(OBJECT)
	$(CC) $(STD) $(OBJECT) -o $(OUT) 

$(OBJECT): $(DEPS)

clean:
	rm *.o
disclean:clean
	rm queue
