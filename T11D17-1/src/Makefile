CC=gcc
FLAGS= -Wall -Wextra -Werror
FILE=../build/Quest_1
FILE2=../build/Quest_2

all: door_struct list_test
door_struct: dmanager_module.o
	$(CC) $(FLAGS) dmanager_module.o -o $(FILE)

dmanager_module.o: dmanager_module.c
	$(CC) $(FLAGS) -c dmanager_module.c

list_test: list.o list_test.o 
	$(CC) $(FLAGS) list.o list_test.o  -o $(FILE2)

list.o: list.c
	$(CC) $(FLAGS) -c list.c

list_test.o: list_test.c
	$(CC) $(FLAGS) -c list_test.c

clean:
	rm -rf *.o ../build/*


rebuild:
	make clean
	make all
