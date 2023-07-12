#include "libs.h"

int print_events(FILE* ptr) {  // OUTPUT
    int is_error = 0;
    events rec;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        fseek(ptr, 0, SEEK_SET);
        fread(&rec, sizeof(events), 1, ptr);
        while (!feof(ptr)) {
            printf("%d %d %d %s %s\n", rec.event_id, rec.module_id, rec.status, rec.date, rec.time);
            fread(&rec, sizeof(events), 1, ptr);
        }
    }
    return is_error;
}

#include "modules.h"

char* getStr() {
    char* str = (char*)malloc(sizeof(char) * 10);
    int size = 0, k = 1;
    char c = ' ';
    scanf("%c", &c);
    if (c == '\n') scanf("%c", &c);
    while (c != '\n') {
        if (size > k * 10) {
            k++;
            char* tmp = (char*)realloc(str, sizeof(char) * 10 * k);
            if (tmp != NULL)
                str = tmp;
            else
                return NULL;
        }
        str[size++] = c;
        scanf("%c", &c);
    }
    str[size] = '\0';
    return str;
}

int getDate(char* date_out) {
    int is_error = 0;
    char* str = getStr();
    int len = strlen(str);
    char* temp = NULL;
    int date[3];
    date[0] = 0;
    date[1] = 0;
    date[2] = 0;
    for (int i = 2; i >= 0; i--) {
        while (*str) {
            if (((*str >= '0') && (*str <= '9')) || (*str == '.')) {
                if (*str == '.') {
                    str++;
                    break;
                }
                date[i] *= 10;
                date[i] += *str - '0';
            } else {
                is_error = 1;
            }
            str++;
        }
    }
    if (!is_error) {
        if (date[2] > 31 || date[1] > 12 || date[0] == 0 || date[1] == 0 || date[2] == 0) {
            is_error = 1;
        }
    }
    if (is_error) {
        free(str - len);
    } else {
        temp = str - len;
    }

    strcpy(date_out, temp);
    if (temp != NULL) free(temp);

    return is_error;
}

int getTime(char* time_out) {
    int is_error = 0;
    char* str = getStr();
    int len = strlen(str);
    char* temp = NULL;
    int date[3];
    date[0] = 0;
    date[1] = 0;
    date[2] = 0;

    for (int i = 2; i >= 0; i--) {
        while (*str) {
            if (((*str >= '0') && (*str <= '9')) || (*str == ':')) {
                if (*str == ':') {
                    str++;
                    break;
                }
                date[i] *= 10;
                date[i] += *str - '0';
            } else {
                is_error = 1;
            }
            str++;
        }
    }
    if (!is_error) {
        if (date[2] > 23 || date[1] > 59 || date[0] > 59) {
            is_error = 1;
        }
    }
    if (is_error) {
        free(str - len);
    } else {
        temp = str - len;
    }

    printf("\ntime_error: %d\n", is_error);
    printf("\ntime  m_arr: %d %d %d\n", date[0], date[1], date[2]);

    strcpy(time_out, temp);
    if (temp != NULL) free(temp);

    return is_error;
}

int selectEvents(FILE* ptr, int count) {  // SELECT
    int is_error = 0;
    events rec;
    int done = 0;
    int i = 0;
    if (count == 0) {
        print_events(ptr);
        done = 1;
    }
    if (ptr == NULL) {
        is_error = 1;
    } else if (!done) {
        fseek(ptr, 0, SEEK_SET);
        fread(&rec, sizeof(events), 1, ptr);
        while (!feof(ptr)) {
            if (i < count) {
                printf("%d %d %d %s %s\n", rec.event_id, rec.module_id, rec.status, rec.date, rec.time);
                fread(&rec, sizeof(events), 1, ptr);
                i++;
            } else {
                break;
            }
        }
    }
    return is_error;
}

int getLastEventsId(FILE* ptr) {
    int id = -1;
    if (ptr != NULL) {
        fseek(ptr, -sizeof(events), SEEK_END);
        fread(&id, sizeof(int), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return id;
}

int checkEventsId(FILE* ptr, int id) {
    int res = 0;
    if ((id >= 0) && (id <= getLastEventsId(ptr))) res = 1;
    return res;
}

events getEventsRecord(int id) {
    printf("Enter record (id: %d)\n", id);
    events rec;
    int input = 1;
    rec.event_id = id;

    // MODULE_ID INPUT
    do {
        printf("> module_id: ");
        if (scanf("%d", &(rec.module_id)) != 1) {
            printf("n/a\n");
        } else {
            input = 0;
        }
    } while (input);

    // STATUS INPUT
    input = 1;
    do {
        printf("> status (0/1): ");
        if (scanf("%d", &(rec.status)) != 1) {
            printf("n/a\n");
        } else if (rec.status != 0 && rec.status != 1) {
            printf("n/a\n");
        } else {
            input = 0;
        }
    } while (input);

    // DATE INPUT
    input = 1;
    do {
        printf("> date (DD.MM.YYYY): ");
        input = getDate(rec.date);
    } while (input);

    input = 1;
    do {
        printf("> time (HH:MM:SS): ");
        input = getTime(rec.time);
    } while (input);

    return rec;
}

int addEventsRecord(FILE* ptr, events rec) {  // ADD
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        fseek(ptr, 0, SEEK_END);
        fwrite(&rec, sizeof(events), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return is_error;
}

//! NOT SURE
int deleteEventsRecord(FILE* ptr, int id) {  // DELETE
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        events rec;
        int i = id;
        fseek(ptr, (i + 1) * sizeof(events), SEEK_SET);
        while (!feof(ptr)) {
            fseek(ptr, (i + 1) * sizeof(events), SEEK_SET);
            if (fread(&rec, sizeof(events), 1, ptr) != 1) break;
            fseek(ptr, i * sizeof(events), SEEK_SET);
            rec.event_id--;
            fwrite(&rec, sizeof(events), 1, ptr);
            i++;
        }
        fseek(ptr, 0, SEEK_SET);
        truncate(events_fpath, i * sizeof(events));
    }
    return is_error;
}

int insertEventsRecord(FILE* ptr, int id, events new_rec) {  // INSERT
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        events rec;
        int i;
        fseek(ptr, -sizeof(events), SEEK_END);
        fread(&i, sizeof(int), 1, ptr);
        while (i >= id) {
            fseek(ptr, i * sizeof(events), SEEK_SET);
            fread(&rec, sizeof(events), 1, ptr);
            fseek(ptr, (i + 1) * sizeof(events), SEEK_SET);
            rec.event_id++;
            fwrite(&rec, sizeof(events), 1, ptr);
            i--;
        }
        fseek(ptr, (i + 1) * sizeof(events), SEEK_SET);
        fwrite(&new_rec, sizeof(events), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return is_error;
}

int changeEventsRecord(FILE* ptr, int id, events rec) {  // CHANGE
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        fseek(ptr, id * sizeof(events), SEEK_SET);
        printf("%d %d %d %s %s\n", rec.event_id, rec.module_id, rec.status, rec.date, rec.time);
        fwrite(&rec, sizeof(events), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return is_error;
}
