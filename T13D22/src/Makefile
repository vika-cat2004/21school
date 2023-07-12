CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD=../build/

all: cipher logging_cipher

cipher: work_with_file.o cipher.o logger.o
	$(CC) $(CFLAGS) work_with_file.o cipher.o logger.o -o $(BUILD)cipher

logging_cipher: work_with_file.o cipher.o logger.o
	$(CC) $(CFLAGS) work_with_file.o cipher.o logger.o -o $(BUILD)logging_cipher

logger.o: logger.c logger.h log_levels.h
	$(CC) $(CFLAGS) logger.c -c

cipher.o: cipher.c
	$(CC) $(CFLAGS) cipher.c -c

work_with_file.o: work_with_file.c work_with_file.h
	$(CC) $(CFLAGS) work_with_file.c -c

clean:
	rm -rf *.o $(BUILD)cipher $(BUILD)logging_cipher

rebuild: clean all