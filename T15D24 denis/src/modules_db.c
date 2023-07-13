#include "database.h"

int main() {
    char filename1[] = "../materials/master_modules.db";
    char filename2[] = "../materials/master_levels.db";
    char filename3[] = "../materials/master_status_events.db";
    int code, db_num;
    char c_help, c1_help;
    while (
        printf("Please choose one operation:\n1. SELECT\n2. INSERT\n3. UPDATE\n4. DELETE\n5. Get all active "
               "additional modules (last module status is 1)\n6. Get all modules at the first memory "
               "level\n7. Set protected mode "
               "for "
               "module by id \n8. Delete modules by ids\n9. Do task\n10. View content\n-1.Exit\n \n Please "
               "choose a table:\n1. "
               "Modules\n2. "
               "Levels\n3. Status events\n"),
        scanf("%d%c", &code, &c_help) >= 0 && !(code == -1 && c_help == '\n')) {
        if (c_help == '\n' && code > 0 && code < 11 && scanf("%d%c", &db_num, &c1_help) >= 0 &&
            c1_help == '\n' && db_num > 0 && db_num < 4) {
            if (code == 1) {
                int id;
                printf("select id:");
                scanf("%d", &id);
                if (!myselect(db_num, id)) printf("no such identifier");
            } else if (code == 2) {
                myinsert(db_num);
            } else if (code == 3) {
                int id;
                printf("select id:");
                scanf("%d", &id);
                if (!myupdate(db_num, id)) printf("no such identifier");
            } else if (code == 4) {
                int id;
                printf("select id:");
                scanf("%d", &id);
                if (!mydelete(db_num, id)) printf("no such identifier");
            } else if (code == 5) {
                active_mod();
            } else if (code == 6) {
                first_mem_lvl();
            } else if (code == 7) {
                protected_mode_id();
            } else if (code == 8) {
                int id;
                printf("press -1 to exit");
                while (printf("\nselect id:"), scanf("%d", &id) == 1 && id != -1)
                    if (!mydelete(db_num, id)) printf("no such identifier");
            } else if (code == 9) {
                do_task();
            } else {
                if (db_num == 1)
                    file_read1(filename1);
                else if (db_num == 2)
                    file_read2(filename2);
                else
                    file_read3(filename3);
            }
        } else {
            c_help = '.';
            while (c_help != '\n') {
                scanf("%c", &c_help);
            }
            printf("n/a\n");
        }
        printf("\n\n");
    }

    int id;
    printf("for binary search enter file number and id:");
    scanf("%d %d", &db_num, &id);
    bin_search(db_num, id);

    return 0;
}
