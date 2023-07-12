CC = gcc
FLAG = -Wall -Werror -Wextra -c

all: Quest_3 build_with_static build_with_dynamic

rebuild: clean all

Quest_3: main_executable_module.o data_io.o data_process.o data_stat.o decision.o 
	$(CC) main_executable_module.o data_io.o data_process.o data_stat.o decision.o -o ../../build/Quest_3

main_executable_module.o: 
	$(CC) $(FLAG) main_executable_module.c

data_io.o: 
	$(CC) $(FLAG) ../data_libs/data_io.c

data_process.o: 
	$(CC) $(FLAG) ../data_module/data_process.c

data_stat.o: 
	$(CC) $(FLAG) ../data_libs/data_stat.c

decision.o: 
	$(CC) $(FLAG) ../yet_another_decision_module/decision.c

data_stat.a: data_stat.o
	ar -rc data_stat.a data_stat.o
	ranlib data_stat.a

build_with_static: main_executable_module.o data_io.o data_process.o data_stat.a decision.o
	$(CC) main_executable_module.o data_io.o data_process.o data_stat.a decision.o -o ../../build/Quest_5

data_process.so:
	$(CC) $(FLAG) -shared -fPIC ../data_module/data_process.c -o data_process.so

build_with_dynamic: data_process.so main_executable_module.o data_stat.o data_io.o decision.o
	$(CC) -L. data_process.so main_executable_module.o data_stat.o data_io.o decision.o -o ../../build/Quest_6
	cp data_process.so ../../build/

clean:
	rm -rf ../*/*.o
	rm -rf ../*/*.a
	rm -rf ../../*/*/*.so
