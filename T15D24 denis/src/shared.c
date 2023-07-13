#include "database.h"

// ENTITY *select(FILE *db, int id);
// int delete_id(FILE *db, int id);
// int insert(FILE *db, ENTITY *entity);
// int update(FILE *db, int id, ENTITY *entity);

int myselect(int db_num, int id) {
    int flag = 1;
    if (db_num == 1) {
        char filename1[] = "../materials/master_modules.db";
        FILE* fp = fopen(filename1, "r+b");
        struct module* temp = select1(fp, id);
        if (temp == NULL)
            flag = 0;
        else {
            printf("\n\n%d | %s | %d | %d | %d\n\n", temp->id, temp->name, temp->mem_lvl, temp->cell_num,
                   temp->del_flag);
            free(temp);
        }
        fclose(fp);
    } else if (db_num == 2) {
        char filename2[] = "../materials/master_levels.db";
        FILE* fp = fopen(filename2, "r+b");
        struct level* temp = select2(fp, id);
        if (temp == NULL)
            flag = 0;
        else {
            printf("\n\n%d | %d | %d\n\n", temp->mem_lvl, temp->cell_num, temp->prot_flag);
            free(temp);
        }
        fclose(fp);
    } else if (db_num == 3) {
        char filename3[] = "../materials/master_status_events.db";
        FILE* fp = fopen(filename3, "r+b");
        struct status_event* temp = select3(fp, id);
        if (temp == NULL)
            flag = 0;
        else {
            printf("\n\n%d | %d | %d | %s | %s\n\n", temp->ev_id, temp->mod_id, temp->new_status,
                   temp->status_date, temp->status_time);
            free(temp);
        }
        fclose(fp);
    }
    return flag;
}

void myinsert(int db_num) {
    if (db_num == 1) {
        char filename1[] = "../materials/master_modules.db";
        FILE* fp = fopen(filename1, "r+b");
        printf("enter:id name mem_lvl cell_num del_flag:");
        struct module temp;
        scanf("%d %20s %d %d %d", &temp.id, temp.name, &temp.mem_lvl, &temp.cell_num, &temp.del_flag);
        insert1(fp, &temp);
        fclose(fp);
    } else if (db_num == 2) {
        char filename2[] = "../materials/master_levels.db";
        FILE* fp = fopen(filename2, "r+b");
        printf("enter: mem_lvl cell_num prot_flag:");
        struct level temp;
        scanf("%d %d %d", &temp.mem_lvl, &temp.cell_num, &temp.prot_flag);
        insert2(fp, &temp);
        fclose(fp);
    } else if (db_num == 3) {
        char filename3[] = "../materials/master_status_events.db";
        FILE* fp = fopen(filename3, "r+b");
        printf("enter: ev_id mod_id new_status status_date status_time:");
        struct status_event temp;
        scanf("%d %d %d %20s %20s", &temp.ev_id, &temp.mod_id, &temp.new_status, temp.status_date,
              temp.status_time);
        insert3(fp, &temp);
        fclose(fp);
    }
}

int myupdate(int db_num, int id) {
    int flag = 1;
    if (db_num == 1) {
        char filename1[] = "../materials/master_modules.db";
        FILE* fp = fopen(filename1, "r+b");
        printf("enter:id name mem_lvl cell_num del_flag:");
        struct module temp;
        scanf("%d %20s %d %d %d", &temp.id, temp.name, &temp.mem_lvl, &temp.cell_num, &temp.del_flag);
        if (!update1(fp, id, &temp)) flag = 0;
        fclose(fp);
    } else if (db_num == 2) {
        char filename2[] = "../materials/master_levels.db";
        FILE* fp = fopen(filename2, "r+b");
        printf("enter: mem_lvl cell_num prot_flag:");
        struct level temp;
        scanf("%d %d %d", &temp.mem_lvl, &temp.cell_num, &temp.prot_flag);
        if (!update2(fp, id, &temp)) flag = 0;
        fclose(fp);
    } else if (db_num == 3) {
        char filename3[] = "../materials/master_status_events.db";
        FILE* fp = fopen(filename3, "r+b");
        printf("enter: ev_id mod_id new_status status_date status_time:");
        struct status_event temp;
        scanf("%d %d %d %20s %20s", &temp.ev_id, &temp.mod_id, &temp.new_status, temp.status_date,
              temp.status_time);
        if (!update3(fp, id, &temp)) flag = 0;
        fclose(fp);
    }
    return flag;
}

int mydelete(int db_num, int id) {
    int flag = 1;
    if (db_num == 1) {
        char filename1[] = "../materials/master_modules.db";
        FILE* fp = fopen(filename1, "r+b");
        if (!delete_id1(fp, id)) flag = 0;
        fclose(fp);
    } else if (db_num == 2) {
        char filename2[] = "../materials/master_levels.db";
        FILE* fp = fopen(filename2, "r+b");
        if (!delete_id2(fp, id)) flag = 0;
        fclose(fp);
    } else if (db_num == 3) {
        char filename3[] = "../materials/master_status_events.db";
        FILE* fp = fopen(filename3, "r+b");
        if (!delete_id3(fp, id)) flag = 0;
        fclose(fp);
    }
    return flag;
}

void active_mod() {
    char filename3[] = "../materials/master_status_events.db";
    FILE* fp = fopen(filename3, "rb");
    int len = get_records_count_in_file3(fp);
    int flag = 0;
    for (int i = 0; i < len; i++) {
        struct status_event temp = read_record_from_file3(fp, i);
        if (1 == temp.new_status) {
            flag = 1;
            printf("%d | %d | %d | %s | %s\n", temp.ev_id, temp.mod_id, temp.new_status, temp.status_date,
                   temp.status_time);
        }
    }
    fclose(fp);
    if (!flag) printf("all modules are disabled\n");
}

void first_mem_lvl() {
    char filename2[] = "../materials/master_levels.db";
    FILE* fp = fopen(filename2, "rb");
    int len = get_records_count_in_file2(fp);
    int flag = 0;
    for (int i = 0; i < len; i++) {
        struct level temp = read_record_from_file2(fp, i);
        if (1 == temp.mem_lvl) {
            flag = 1;
            printf("%d | %d | %d\n", temp.mem_lvl, temp.cell_num, temp.prot_flag);
        }
    }
    fclose(fp);
    if (!flag) printf("no modules with 1 memory level\n");
}

void protected_mode_id() {
    printf("enter id:");
    int id;
    scanf("%d", &id);
    char filename2[] = "../materials/master_levels.db";
    FILE* fp = fopen(filename2, "r+b");
    int len = get_records_count_in_file2(fp);
    int flag = 0;
    for (int i = 0; i < len && !flag; i++) {
        struct level temp = read_record_from_file2(fp, i);
        if (id == temp.mem_lvl) {
            flag = 1;
            temp.prot_flag = 1;
            update2(fp, id, &temp);
        }
    }
    fclose(fp);
    if (!flag) printf("no such ID\n");
}

void do_task() {
    char filename3[] = "../materials/master_status_events.db";
    FILE* fp = fopen(filename3, "r+b");
    int len = get_records_count_in_file3(fp);
    for (int i = 1; i < len; i++) {
        struct status_event temp = read_record_from_file3(fp, i);
        if (1 == temp.new_status) {
            temp.new_status = 0;
            write_record_in_file3(fp, &temp, i);
        }
    }
    struct status_event temp = read_record_from_file3(fp, 0);
    temp.new_status = 20;
    write_record_in_file3(fp, &temp, 0);
    fclose(fp);

    char filename2[] = "../materials/master_levels.db";
    fp = fopen(filename2, "r+b");
    len = get_records_count_in_file2(fp);
    for (int i = 0; i < len; i++) {
        struct level temp2 = read_record_from_file2(fp, i);
        if (1 == temp2.mem_lvl) {
            temp2.prot_flag = 1;
            write_record_in_file2(fp, &temp2, i);
        }
    }
    fclose(fp);

    char filename1[] = "../materials/master_modules.db";
    fp = fopen(filename1, "r+b");
    len = get_records_count_in_file1(fp);
    for (int i = 1; i < len; i++) {
        struct module temp1 = read_record_from_file1(fp, i);
        temp1.del_flag = 1;
        write_record_in_file1(fp, &temp1, i);
    }
    struct module temp1 = read_record_from_file1(fp, 0);
    temp1.mem_lvl = 1;
    temp1.cell_num = 1;
    write_record_in_file1(fp, &temp1, 0);
    temp1 = read_record_from_file1(fp, 0);
    printf("%d %s %d %d %d", temp1.id, temp1.name, temp1.mem_lvl, temp1.cell_num, temp1.del_flag);
    fclose(fp);
}

void bin_search(int db_num, int id) {
    if (db_num == 1) {
        char filename1[] = "../materials/master_modules.db";
        FILE* fp = fopen(filename1, "rb");
        int low, high;
        low = 0;
        high = get_records_count_in_file1(fp) - 1;
        while (low <= high) {
            int middle = (low + high) / 2;
            struct module temp = read_record_from_file1(fp, middle);
            if (id < temp.id)
                high = middle - 1;
            else if (id > temp.id)
                low = middle + 1;
            else {
                printf("\n\n%d | %s | %d | %d | %d\n\n", temp.id, temp.name, temp.mem_lvl, temp.cell_num,
                       temp.del_flag);
                break;
            }
        }

        fclose(fp);
    } else if (db_num == 2) {
        char filename2[] = "../materials/master_levels.db";
        FILE* fp = fopen(filename2, "rb");
        int low, high;
        low = 0;
        high = get_records_count_in_file2(fp) - 1;
        while (low <= high) {
            int middle = (low + high) / 2;
            struct level temp = read_record_from_file2(fp, middle);
            if (id < temp.mem_lvl)
                high = middle - 1;
            else if (id > temp.mem_lvl)
                low = middle + 1;
            else {
                printf("\n\n%d | %d | %d\n\n", temp.mem_lvl, temp.cell_num, temp.prot_flag);
                break;
            }
        }

        fclose(fp);
    } else if (db_num == 3) {
        char filename3[] = "../materials/master_status_events.db";
        FILE* fp = fopen(filename3, "rb");
        int low, high;
        low = 0;
        high = get_records_count_in_file3(fp) - 1;
        while (low <= high) {
            int middle = (low + high) / 2;
            struct status_event temp = read_record_from_file3(fp, middle);
            if (id < temp.ev_id)
                high = middle - 1;
            else if (id > temp.ev_id)
                low = middle + 1;
            else {
                printf("\n\n%d | %d | %d | %s | %s\n\n", temp.ev_id, temp.mod_id, temp.new_status,
                       temp.status_date, temp.status_time);
                break;
            }
        }
        fclose(fp);
    }
}
