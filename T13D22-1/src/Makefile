CC = gcc
CFLAGS = -Wall -Wextra -Werror
BUILD = ../build
NAME = cipher

all: cipher

cipher: cipher.o
	$(CC) $(CFLAGS) cipher.o -o $(BUILD)/$(NAME)
	

cipher.o: cipher.c
	$(CC) $(CFLAGS) -c cipher.c

clean:
	rm -rf $(BUILD)/$(NAME)

rebuild:
	make clean
	clean all
