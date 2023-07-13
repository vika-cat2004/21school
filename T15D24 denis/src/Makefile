CC=gcc
CFLAGS= -Wall -Werror -Wextra
FINALPATH = ../build/


all:  build_db

 build_db:
	$(CC)  $(CFLAGS) master_modules.c modules_db.c master_levels.c master_status_events.c shared.c  -o $(FINALPATH)DB

clean:
	rm -rf *.o  $(FINALPATH)Quest* 

rebuild: clean all
