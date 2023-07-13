#ifndef DB
#define DB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define ENTITY int

struct module {
    int id;
    char name[30];
    int mem_lvl;
    int cell_num;
    int del_flag;
};

struct level {
    int mem_lvl;
    int cell_num;
    int prot_flag;
};

struct status_event {
    int ev_id;
    int mod_id;
    int new_status;
    char status_date[11];
    char status_time[9];
};

// ENTITY *select(FILE *db, int id);
// int delete_id(FILE *db, int id);
// int insert(FILE *db, ENTITY *entity);
// int update(FILE *db, int id, ENTITY *entity);

struct module read_record_from_file1(FILE *pfile, int index);
int write_record_in_file1(FILE *pfile, const struct module *record_to_write, int index);
void swap_records_in_file1(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes1(FILE *pfile);
int get_records_count_in_file1(FILE *pfile);
struct module *select1(FILE *db, int id);
int delete_id1(FILE *db, int id);
int insert1(FILE *db, struct module *entity);
int update1(FILE *db, int id, struct module *entity);
void file_read1(char *filename);

struct level read_record_from_file2(FILE *pfile, int index);
int write_record_in_file2(FILE *pfile, const struct level *record_to_write, int index);
void swap_records_in_file2(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes2(FILE *pfile);
int get_records_count_in_file2(FILE *pfile);
struct level *select2(FILE *db, int id);
int delete_id2(FILE *db, int id);
int insert2(FILE *db, struct level *entity);
int update2(FILE *db, int id, struct level *entity);
void file_read2(char *filename);

struct status_event read_record_from_file3(FILE *pfile, int index);
int write_record_in_file3(FILE *pfile, const struct status_event *record_to_write, int index);
void swap_records_in_file3(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes3(FILE *pfile);
int get_records_count_in_file3(FILE *pfile);
struct status_event *select3(FILE *db, int id);
int delete_id3(FILE *db, int id);
int insert3(FILE *db, struct status_event *entity);
int update3(FILE *db, int id, struct status_event *entity);
void file_read3(char *filename);

int myselect(int db_num, int id);
void myinsert(int db_num);
int myupdate(int db_num, int id);
int mydelete(int db_num, int id);
void active_mod();
void first_mem_lvl();
void protected_mode_id();
void do_task();
void bin_search(int db_num, int id);

#endif