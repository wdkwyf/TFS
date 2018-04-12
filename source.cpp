#include<stdio.h>
#include<string.h>
#include"ext2.h"

int main(int argc, char **argv) {
    char command[10], temp[9];
    int type;
    initialize_memory();
    while (1) {
        printf("%s]#", current_path);
        scanf("%s", command);
        if (!strcmp(command, "cd")) {
            scanf("%s", temp);
            cd(temp);
        } else if (!strcmp(command, "test")) {
            printBlockStatus();
        } else if (!strcmp(command, "chmod")) {
            scanf("%s", temp);
            scanf("%d", &type);
            chmod_file(temp, type);
        } else if (!strcmp(command, "mkdir")) {
            scanf("%s", temp);
            mkdir(temp, 2);
        } else if (!strcmp(command, "mkf")) {
            scanf("%s", temp);
            mkdir(temp, 1);
        } else if (!strcmp(command, "rmdir")) {
            scanf("%s", temp);
            rmdir(temp);
        } else if (!strcmp(command, "rm")) {
            scanf("%s", temp);
            del(temp);
        } else if (!strcmp(command, "open")) {
            scanf("%s", temp);
            open_file(temp);
        } else if (!strcmp(command, "close")) {
            scanf("%s", temp);
            close_file(temp);
        } else if (!strcmp(command, "read")) {
            scanf("%s", temp);
            read_file(temp);
        } else if (!strcmp(command, "write")) {
            scanf("%s\n", temp);
            write_file(temp);
        } else if (!strcmp(command, "ls")) {
            ls();
        } else if (!strcmp(command, "format")) {
            char tempch;
            printf("format will erase all the data in the disk\n");
            printf("Are you sure?y/n:\n");
            while ((tempch = getchar()) != '\n' && tempch != EOF);
            scanf("%c", &tempch);
            if (tempch == 'y' || tempch == 'Y') {
                format();
            } else {
                printf("format disk canceled\n");
            }
        } else if (!strcmp(command, "help") || !strcmp(command, "h")) {
            help();
        } else if (!strcmp(command, "ckdisk")) {
            check_disk();
        } else if (!strcmp(command, "quit")) {
            break;
        } else {
            printf("No this command .please check!\n");
            help();
        }
    }
    return 0;
}
