.PHONY = state_sort state_search clear_state check lint clean rebuild
FLAGS  = -Wall -Werror -Wextra

all: state_search state_sort clear_state

state_sort: state_sort.c input.c sort.c
	gcc $(FLAGS) -c state_sort.c input.c sort.c
	gcc state_sort.o input.o sort.o -o ../build/Quest_1

state_search: state_search.c input.c
	gcc $(FLAGS) -c state_search.c input.c
	gcc state_search.o input.o -o ../build/Quest_2  

clear_state: clear_state.c input.c
	gcc $(FLAGS) -c clear_state.c input.c
	gcc clear_state.o input.o -o ../build/Quest_3

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.[ch]

lint:
	python3 ../materials/linters/cpplint.py --extensions=c --headers=h --linelength=110 --filter=-runtime/int,-legal/copyright,-build/include_subdir,-build/include,-readability/casting,-runtime/threadsafe_fn,-runtime/printf *.[ch]

clean:
	rm *.o
	rm ../build/*

rebuild: clean all