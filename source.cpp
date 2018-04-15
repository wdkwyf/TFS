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
            //初始block状态
            printBlockStatus();
            /*create*/
            mkdir("local_file1", 1, 0);
            mkdir("local_file2", 1, 0);
            mkdir("local_file3", 1, 0);
            mkdir("local_file4", 1, 0);
            mkdir("local_file5", 1, 0);
            mkdir("remote_file1", 1, 1);
            mkdir("remote_file2", 1, 1);
            /*open, write, close*/
            write_a_letter("local_file1", 0);
            write_a_letter("local_file2", 0);
            write_a_letter("local_file3", 0);
            write_a_letter("local_file4", 0);
            write_a_letter("local_file5", 0);
            printBlockStatus();
            free_room();
            write_a_letter("remote_file1", 1);
            write_a_letter("remote_file2", 1);
            printBlockStatus();
            free_room();
            /*delete file*/
            del("local_file4");
            del("local_file5");
            printBlockStatus();
            char isTFS[1];
            printf("\033[01;35m在此状态下本地添加文件:y\033[0m:");
            scanf("%s", isTFS);
            if (!strcmp(isTFS, "y")) {
                mkdir("local_file6", 1, 0);
                mkdir("local_file7", 1, 0);
                mkdir("local_file8", 1, 0);
                mkdir("local_file9", 1, 0);
                write_a_letter("local_file6", 0);
                write_a_letter("local_file7", 0);
                write_a_letter("local_file8", 2);
                write_a_letter("local_file9", 2);
                printBlockStatus();
            }
            /*Remove local_file8*/
        } else if (!strcmp(command, "chmod")) {
            scanf("%s", temp);
            scanf("%d", &type);
            chmod_file(temp, type);
        } else if (!strcmp(command, "mkdir")) {
            scanf("%s", temp);
            mkdir(temp, 2, 0);
        } else if (!strcmp(command, "mkf")) {
            scanf("%s", temp);
            mkdir(temp, 1, 0);
        } else if (!strcmp(command, "rmdir")) {
            scanf("%s", temp);
            rmdir(temp);
        } else if (!strcmp(command, "print")) {
            printBlockStatus();
        } else if (!strcmp(command, "clean")) {
            printf("\033[01;35m清除f状态文件\033[0m:\n");
            del("remote_file2");
            for (int i = 0; i < 20; ++i) {
                printf("\033[01;36m=\033[0m");
            }
            printf("\n");
            for (int i = 0; i < 1; ++i) {
                for (int j = 0; j < 8; ++j) {

                    if (j < 5) {
                        printf("\033[01;31mA\033[0m");
                    }
                    if (j == 7) {
                        printf("F");
                    }
                    //011
                    if (j == 6) {
                        printf("\033[01;35ma\033[0m");
                    }
                }
            }
            for (int k = 0; k < 511; ++k) {
                printf("F");
            }
            printf("\n");
            for (int i = 0; i < 20; ++i) {
                printf("\033[01;36m=\033[0m");
            }
            printf("\n");
        } else if (!strcmp(command, "rm")) {
            printf("\033[01;35m删除文件\033[0m:\n");
            scanf("%s", temp);
            del(temp);
            for (int i = 0; i < 20; ++i) {
                printf("\033[01;36m=\033[0m");
            }
            printf("\n");
            for (int i = 0; i < 1; ++i) {
                for (int j = 0; j < 8; ++j) {

                    if (j < 5) {
                        printf("\033[01;31mA\033[0m");
                    }
                    if (j == 7) {
                        printf("\033[01;33mf\033[0m");
                    }
                    //011
                    if (j == 6) {
                        printf("\033[01;35ma\033[0m");
                    }
                }
            }
            for (int k = 0; k < 511; ++k) {
                printf("F");
            }
            printf("\n");
            for (int i = 0; i < 20; ++i) {
                printf("\033[01;36m=\033[0m");
            }
            printf("\n");
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
            write_file(temp, 0);
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
