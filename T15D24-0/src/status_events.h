#ifndef SRC_STATUS_EVENTS_H_
#define SRC_STATUS_EVENTS_H_

#include "libs.h"

/*
struct events {
    int event_id;
    int module_id;
    int status;
    char date[11];
    char time[9];
};

*/

int checkEventsId(FILE* ptr, int id);
int getLastEventsId(FILE* ptr);
int print_events(FILE* ptr);
events getEventsRecord(int id);
int addEventsRecord(FILE* ptr, events rec);
int deleteEventsRecord(FILE* ptr, int id);
int changeEventsRecord(FILE* ptr, int id, events rec);
int insertEventsRecord(FILE* ptr, int id, events rec);
int selectEvents(FILE* ptr, int count);

int getDate(char* date);
int getTime(char* time);
char* getStr();

#endif  // SRC_STATUS_EVENTS_H_
