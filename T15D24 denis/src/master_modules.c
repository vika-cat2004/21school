#include "database.h"

void file_read1(char *filename) {
    FILE *fp;
    struct module temp;
    fp = fopen(filename, "rb");
    int len = get_records_count_in_file1(fp);
    for (int i = 0; i < len; i++) {
        fread(&temp, sizeof(struct module), 1, fp);
        printf("%d | %s | %d | %d | %d", temp.id, temp.name, temp.mem_lvl, temp.cell_num, temp.del_flag);
        if (i != len - 1) printf("\n");
    }
    fclose(fp);
}

struct module read_record_from_file1(FILE *pfile, int index) {
    int offset = index * sizeof(struct module);
    fseek(pfile, offset, SEEK_SET);
    struct module record;
    fread(&record, sizeof(struct module), 1, pfile);
    rewind(pfile);
    return record;
}

int write_record_in_file1(FILE *pfile, const struct module *record_to_write, int index) {
    int offset = index * sizeof(struct module);
    fseek(pfile, offset, SEEK_SET);
    int flag = fwrite(record_to_write, sizeof(struct module), 1, pfile);
    fflush(pfile);
    rewind(pfile);
    return flag;
}

void swap_records_in_file1(FILE *pfile, int record_index1, int record_index2) {
    struct module record1 = read_record_from_file1(pfile, record_index1);
    struct module record2 = read_record_from_file1(pfile, record_index2);
    write_record_in_file1(pfile, &record1, record_index2);
    write_record_in_file1(pfile, &record2, record_index1);
}

int get_file_size_in_bytes1(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file1(FILE *pfile) { return get_file_size_in_bytes1(pfile) / sizeof(struct module); }

struct module *select1(FILE *db, int id) {
    int len = get_records_count_in_file1(db), flag = 1;
    struct module *temp = (struct module *)malloc(sizeof(struct module));
    for (int i = 0; i < len && flag; i++) {
        if (id == read_record_from_file1(db, i).id) {
            *temp = read_record_from_file1(db, i);
            flag = 0;
        }
    }
    if (flag) temp = NULL;
    return temp;
}

int delete_id1(FILE *db, int id) {
    int len = get_records_count_in_file1(db);
    int flag = 1;
    for (int j = 0; j < len && flag; j++) {
        if (id == read_record_from_file1(db, j).id) {
            for (int i = j; i < len - 1; i++) {
                swap_records_in_file1(db, i, i + 1);
            }
            flag = 0;
        }
    }
    ftruncate(fileno(db), sizeof(struct module) * (len - 1));
    return !flag;
}

int insert1(FILE *db, struct module *entity) {
    int flag = write_record_in_file1(db, entity, get_records_count_in_file1(db));
    return flag;
}

int update1(FILE *db, int id, struct module *entity) {
    int len = get_records_count_in_file1(db);
    int flag = 1;
    for (int i = 0; i < len && flag; i++) {
        if (id == read_record_from_file1(db, i).id) {
            write_record_in_file1(db, entity, i);
            flag = 0;
        }
    }
    return !flag;
}
