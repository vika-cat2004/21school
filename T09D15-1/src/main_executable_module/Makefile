CC =gcc
CFLAGS= -Wall -Wextra -Werror

all: main

quest_3: data_io.o data_stat.o data_process.o decision.o main_executable_module.o
	$(CC) data_io.o data_stat.o data_process.o decision.o main_executable_module.o -o ../../build/Quest_3

data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c

data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) -c ../data_module/data_process.c

decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c

main_executable_module.o: main_executable_module.c 
	$(CC) $(CFLAGS) -c main_executable_module.c

 data_stat.a: 
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c -o ../data_libs/data_stat.o
	ar rc data_stat.a ../data_libs/data_stat.o 
	ranlib data_stat.a

build_with_static:
	make data_stat.a
	$(CC) $(CFLAGS) data_io.o data_stat.a data_process.o decision.o main_executable_module.o -o ../../build/Quest_5

build_with_dynamic: data_process.so
	$(CC) $(CFLAGS) ../data_libs/data_io.o ../data_libs/data_stat.o decision.o main_executable_module.o -o ../../build/Quest_6

data_process.so:
	$(CC) -shared $(CFLAGS) -o -c -fPIC ../data_module/data_process.c ../data_libs/data_stat.c ../data_module/data_process.c ../data_libs/data_stat.c
	cp libdata_process.so../../build/Quest_6

clean:
	rm -f *.o quest_3
	rm -f ../../build/* *.o *.a *.out *.so

rebuild:
	make clean
