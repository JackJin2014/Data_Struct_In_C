OBJECT	=tree.o tree_test.o
CC		=gcc
CFLAGS	= -g -c -I. -I../
STD = -std=c99
TARGET = tree_test
OUT = tree

DEPS = tree.h

all : $(TARGET)
$(TARGET): $(OBJECT)
	$(CC) $(STD) $(OBJECT) -o $(OUT) 

$(OBJECT): $(DEPS)

clean:
	rm *.o
disclean:clean
	rm tree*exe*
