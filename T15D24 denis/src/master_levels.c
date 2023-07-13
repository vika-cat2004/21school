#include "database.h"

void file_read2(char *filename) {
    FILE *fp;
    struct level temp;
    fp = fopen(filename, "rb");
    int len = get_records_count_in_file2(fp);
    for (int i = 0; i < len; i++) {
        fread(&temp, sizeof(struct level), 1, fp);
        printf("%d | %d | %d", temp.mem_lvl, temp.cell_num, temp.prot_flag);
        if (i != len - 1) printf("\n");
    }
    fclose(fp);
}

struct level read_record_from_file2(FILE *pfile, int index) {
    int offset = index * sizeof(struct level);
    fseek(pfile, offset, SEEK_SET);
    struct level record;
    fread(&record, sizeof(struct level), 1, pfile);
    rewind(pfile);
    return record;
}

int write_record_in_file2(FILE *pfile, const struct level *record_to_write, int index) {
    int offset = index * sizeof(struct level);
    fseek(pfile, offset, SEEK_SET);
    int flag = fwrite(record_to_write, sizeof(struct level), 1, pfile);
    fflush(pfile);
    rewind(pfile);
    return flag;
}

void swap_records_in_file2(FILE *pfile, int record_index1, int record_index2) {
    struct level record1 = read_record_from_file2(pfile, record_index1);
    struct level record2 = read_record_from_file2(pfile, record_index2);
    write_record_in_file2(pfile, &record1, record_index2);
    write_record_in_file2(pfile, &record2, record_index1);
}

int get_file_size_in_bytes2(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file2(FILE *pfile) { return get_file_size_in_bytes2(pfile) / sizeof(struct level); }

struct level *select2(FILE *db, int id) {
    int len = get_records_count_in_file2(db), flag = 1;
    struct level *temp = (struct level *)malloc(sizeof(struct level));
    for (int i = 0; i < len && flag; i++) {
        if (id == read_record_from_file2(db, i).mem_lvl) {
            *temp = read_record_from_file2(db, i);
            flag = 0;
        }
    }
    if (flag) temp = NULL;
    return temp;
}

int delete_id2(FILE *db, int id) {
    int len = get_records_count_in_file2(db);
    int flag = 1;

    for (int j = 0; j < len && flag; j++) {
        if (id == read_record_from_file2(db, j).mem_lvl) {
            for (int i = j; i < len - 1; i++) swap_records_in_file2(db, i, i + 1);
            flag = 0;
        }
    }
    ftruncate(fileno(db), sizeof(struct level) * (len - 1));
    return !flag;
}

int insert2(FILE *db, struct level *entity) {
    int flag = write_record_in_file2(db, entity, get_records_count_in_file2(db));
    return flag;
}

int update2(FILE *db, int id, struct level *entity) {
    int len = get_records_count_in_file2(db);
    int flag = 1;
    for (int i = 0; i < len && flag; i++) {
        if (id == read_record_from_file2(db, i).mem_lvl) {
            write_record_in_file2(db, entity, i);
            flag = 0;
        }
    }
    return !flag;
}