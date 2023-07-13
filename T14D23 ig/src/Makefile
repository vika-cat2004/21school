FLAGS = -Wall -Werror -Wextra
BUILD = ../build/Quest

all: state_sort state_search

state_sort: state_sort.c mass_file.c file_IO.c
	gcc $(FLAGS) state_sort.c mass_file.c file_IO.c sort.c -o $(BUILD)_1

state_search: state_search.c mass_file.c file_IO.c
	gcc $(FLAGS) state_search.c mass_file.c file_IO.c sort.c -o $(BUILD)_2

clean:
	rm -rf *.o *.a *.so ../build/*

rebuild: clean all
