CC=gcc
CCFLAGS=-Wall -Wextra -Werror -g2 #-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment
OUTPUT_DIR=../build

all: format_project print_module documentation_module bst_create_test bst_insert_test bst_traverse_test launch 

print_module:
	$(CC) $(CCFLAGS) -DQ1 print_module.c main_module_entry_point.c -o $(OUTPUT_DIR)/Quest_1

documentation_module:
	$(CC) $(CCFLAGS) -DQ2 documentation_module.c main_module_entry_point.c print_module.c -o $(OUTPUT_DIR)/Quest_2

bst_create_test:
	$(CC) $(CCFLAGS) -DQ3 bst.c bst_create_test.c -o $(OUTPUT_DIR)/Quest_3

bst_insert_test:
	$(CC) $(CCFLAGS) -DQ4 bst.c bst_create_test.c -o $(OUTPUT_DIR)/Quest_4

bst_traverse_test:
	$(CC) $(CCFLAGS) -DQ5 bst.c bst_traverse_test.c -o $(OUTPUT_DIR)/Quest_5

launch:
	./$(OUTPUT_DIR)/Quest_1
	./$(OUTPUT_DIR)/Quest_2
	./$(OUTPUT_DIR)/Quest_3
	./$(OUTPUT_DIR)/Quest_4
	./$(OUTPUT_DIR)/Quest_5

clean:
	find ./../build -type f -name 'Quest*'      -delete
	find ./../ -type f -name '*.gch'  			-delete
	find ./../ -type f -name '*.o'    			-delete
	find ./../ -type f -name 'a'      			-delete
	find ./../ -name '*.dSYM'      				-exec rm -rv {} +
	find ./../ -type f -name '*.out'  			-delete
	find ./../build/ -type f -name 'a'  		-delete

format_project:
	clang-format -i *.c *.h
	cppcheck --check-config --enable=all --suppress=missingIncludeSystem .
