#include "shared.h"

#include "functions.h"
#include "levels.h"
#include "libs.h"
#include "modules.h"
#include "status_events.h"

int getChoice(int gap1, int gap2) {
    int num;
    printf("> ");
    while (1) {
        if (scanf("%d", &num) != 1)
            printf("n/a\n");
        else if ((num > gap2) || (num < gap1))
            printf("n/a\n");
        else
            break;
    }
    return num;
}

int showTables() {
    int is_error = 0;
    FILE* mptr = fopen(modules_fpath, "rb");
    FILE* lptr = fopen(levels_fpath, "rb");
    FILE* eptr = fopen(events_fpath, "rb");
    if ((mptr == NULL) || (lptr == NULL) || (eptr == NULL)) {
        is_error = 1;
    } else {
        printf("MODULES:\n");
        print_modules(mptr);
        printf("=======================\nLEVELS:\n");
        print_levels(lptr);
        printf("=======================\nEVENTS:\n");
        print_events(eptr);
    }
    fclose(mptr);
    fclose(lptr);
    fclose(eptr);
    return is_error;
}

int modulesControll() {
    int is_error = 0;
    int choice;
    int id;
    int flag = 1;
    modules rec;
    FILE* ptr = fopen(modules_fpath, "r+b");
    while (flag) {
        printMenu("MODULES");
        choice = getChoice(-1, 5);
        switch (choice) {
            case 0:
                print_modules(ptr);
                break;
            case 1:
                id = getLastId(ptr);
                rec = getModulesRecord(id + 1);
                is_error = addModulesRecord(ptr, rec);
                print_modules(ptr);
                break;
            case 2:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkModulesId(ptr, id)) {
                    rec = getModulesRecord(id);
                    is_error = insertModulesRecord(ptr, id, rec);
                    print_modules(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case 3:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkModulesId(ptr, id)) {
                    rec = getModulesRecord(id);
                    is_error = changeModulesRecord(ptr, id, rec);
                    print_modules(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case 4:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkModulesId(ptr, id)) {
                    deleteModulesRecord(ptr, id);
                    print_modules(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case 5:
                printf("> Specify records count to output (0 for all): ");
                id = getChoice(0, 1000000);
                selectModules(ptr, id);
                break;
            case -1:
                flag = 0;
                break;
        }
        if (is_error) flag = 0;
    }
    return is_error;
}

void printMenu(const char* table_name) {
    printf(
        "==============================\n"
        "    CURRENT TABLE: %7s\n"
        "  0. Show all records\n  1. Add record\n  2. Insert record\n"
        "  3. Update record\n  4. Delete record\n  5. Select record\n"
        "  -1. BACK\n"
        "==============================\n",
        table_name);
}

int levelsControll() {
    int is_error = 0;
    int choice;
    int id;
    int flag = 1;
    levels rec;
    FILE* ptr = fopen(levels_fpath, "r+b");
    while (flag) {
        printMenu("LEVELS");
        choice = getChoice(-1, 5);
        switch (choice) {
            case 0:
                print_levels(ptr);
                break;
            case 1:
                rec = getLevelsRecord();
                is_error = addLevelsRecord(ptr, rec);
                print_levels(ptr);
                break;
            case 2:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkLevelsId(ptr, id)) {
                    rec = getLevelsRecord();
                    is_error = insertLevelsRecord(ptr, id, rec);
                    print_levels(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case 3:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkLevelsId(ptr, id)) {
                    rec = getLevelsRecord();
                    is_error = changeLevelsRecord(ptr, id, rec);
                    print_levels(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case 4:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkLevelsId(ptr, id)) {
                    is_error = deleteLevelsRecord(ptr, id);
                    print_levels(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case 5:
                printf("> Specify records count to output (0 for all): ");
                id = getChoice(0, 1000000);
                selectLevels(ptr, id);
                break;
            case -1:
                flag = 0;
                break;
        }
        if (is_error) flag = 0;
    }
    return is_error;
}

int eventsControll() {
    int is_error = 0;
    int choice;
    int id = 0;
    int flag = 1;
    events rec;
    FILE* ptr = fopen(events_fpath, "r+b");
    while (flag) {
        // printMenu2();
        printMenu("EVENTS");
        choice = getChoice(-1, 5);
        switch (choice) {
            case 0:
                print_events(ptr);
                break;
            case 1:
                id = getLastEventsId(ptr);
                id++;
                rec = getEventsRecord(id);
                is_error = addEventsRecord(ptr, rec);
                print_events(ptr);
                break;
            case 2:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkEventsId(ptr, id)) {
                    rec = getEventsRecord(id);
                    is_error = insertEventsRecord(ptr, id, rec);
                    print_events(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case 3:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkEventsId(ptr, id)) {
                    rec = getEventsRecord(id);
                    is_error = changeEventsRecord(ptr, id, rec);
                    print_events(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case 4:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkEventsId(ptr, id)) {
                    is_error = deleteEventsRecord(ptr, id);
                    print_events(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case 5:
                printf("> Specify records count to output (0 for all): ");
                id = getChoice(0, 1000000);
                selectEvents(ptr, id);
                break;
            case -1:
                flag = 0;
                break;
        }
        if (is_error) flag = 0;
    }
    return is_error;
}
