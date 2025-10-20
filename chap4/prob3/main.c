#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[256];
    int count = 1;

    if (argc != 2) {
        printf("사용법: %s <파일이름>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("파일 열기 오류: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%3d: %s", count, line);
        count++;
    }

    fclose(fp);
    return 0;
}

