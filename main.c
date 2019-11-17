#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

void ls(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    ls(argc, argv);

    return 0;
}

/**
 * 模拟 ls 命令
 * @param argc
 * @param argv
 */
void ls(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) {
        printf("参数数量不对。");
        exit(0);
    }

    if ((dp = opendir(argv[1])) == NULL) {
        printf("不能打开。");

        exit(0);
    }

    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp -> d_name);
    }

    closedir(dp);
}
