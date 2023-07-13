#include "database.h"

void file_read3(char *filename) {
    FILE *fp;
    struct status_event temp;
    fp = fopen(filename, "rb");
    int len = get_records_count_in_file3(fp);
    for (int i = 0; i < len; i++) {
        fread(&temp, sizeof(struct status_event), 1, fp);
        printf("%d | %d | %d | %s | %s", temp.ev_id, temp.mod_id, temp.new_status, temp.status_date,
               temp.status_time);
        if (i != len - 1) printf("\n");
    }
    fclose(fp);
}

struct status_event read_record_from_file3(FILE *pfile, int index) {
    int offset = index * sizeof(struct status_event);
    fseek(pfile, offset, SEEK_SET);
    struct status_event record;
    fread(&record, sizeof(struct status_event), 1, pfile);
    rewind(pfile);
    return record;
}

int write_record_in_file3(FILE *pfile, const struct status_event *record_to_write, int index) {
    int offset = index * sizeof(struct status_event);
    fseek(pfile, offset, SEEK_SET);
    int flag = fwrite(record_to_write, sizeof(struct status_event), 1, pfile);
    fflush(pfile);
    rewind(pfile);
    return flag;
}

void swap_records_in_file3(FILE *pfile, int record_index1, int record_index2) {
    struct status_event record1 = read_record_from_file3(pfile, record_index1);
    struct status_event record2 = read_record_from_file3(pfile, record_index2);
    write_record_in_file3(pfile, &record1, record_index2);
    write_record_in_file3(pfile, &record2, record_index1);
}

int get_file_size_in_bytes3(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file3(FILE *pfile) {
    return get_file_size_in_bytes3(pfile) / sizeof(struct status_event);
}

struct status_event *select3(FILE *db, int id) {
    int len = get_records_count_in_file3(db), flag = 1;
    struct status_event *temp = (struct status_event *)malloc(sizeof(struct status_event));
    for (int i = 0; i < len && flag; i++) {
        if (id == read_record_from_file3(db, i).mod_id) {
            *temp = read_record_from_file3(db, i);
            flag = 0;
        }
    }
    if (flag) temp = NULL;
    return temp;
}

int delete_id3(FILE *db, int id) {
    int len = get_records_count_in_file3(db);
    int flag = 1;

    for (int j = 0; j < len && flag; j++) {
        if (id == read_record_from_file3(db, j).mod_id) {
            for (int i = j; i < len - 1; i++) swap_records_in_file3(db, i, i + 1);
            flag = 0;
        }
    }
    ftruncate(fileno(db), sizeof(struct status_event) * (len - 1));
    return !flag;
}

int insert3(FILE *db, struct status_event *entity) {
    int flag = write_record_in_file3(db, entity, get_records_count_in_file3(db));
    return flag;
}

int update3(FILE *db, int id, struct status_event *entity) {
    int len = get_records_count_in_file3(db);
    int flag = 1;
    for (int i = 0; i < len && flag; i++) {
        if (id == read_record_from_file3(db, i).mod_id) {
            write_record_in_file3(db, entity, i);
            flag = 0;
        }
    }
    return !flag;
}
