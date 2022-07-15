CC=gcc
CFLAGS=-g -Wall
OBJS=main.o caesar.o
TARGET=cipher

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: main.c cipher.h
caesar.o: caesar.c cipher.h

clean:
	rm -f *.o