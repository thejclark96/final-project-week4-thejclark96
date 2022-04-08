UNAME=$(shell uname)

CCFLAGS=-Wall -O3 -std=gnu99
CC=gcc

all: app

sjf: main.o physics.o app.o ctest.h sjftests.o
	$(CC) $(LDFLAGS) main.o physics.o app.o sjftests.o -o shortestjobfirst

remake: clean all

%.o: %.c ctest.h
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f shortestjobfirst *.o
