CC=gcc
FLAGS= -Wall -Wextra -Werror
FILE=../build/Quest_1
FILE2=../build/Quest_2
XTRA=
Q1_MACRO=QUEST1_STRLEN
Q2_MACRO=QUEST2_STRCMP

all: 

strlen_tests: quest01_flags s21_string_test.o s21_string.o 
	$(CC) $(FLAGS) s21_string_test.o s21_string.o -o $(FILE)

quest01_flags:
	$(eval XTRA = -DQUEST1_STRCMP)

s21_string_test.o: s21_string_test.c 
	$(CC) $(FLAGS) $(XTRA) -c s21_string_test.c 

s21_string.o: s21_string.c 
	$(CC) $(FLAGS) -c s21_string.c

strcmp_tests: quest02_flags s21_string_test.o s21_string.o 
	$(CC) $(FLAGS) s21_string_test.o s21_string.o -o $(FILE2)

quest02_flags:
	$(eval XTRA = -DQUEST2_STRLEN)

clean:
	rm -rf *.o ../build/*

