#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[]) {
    FILE *fp;
    Student s;

    // 명령행 인자 확인
    if (argc != 2) {
        printf("사용법: %s <파일이름>\n", argv[0]);
        return 1;
    }

    // 파일 열기
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("파일 열기 오류: %s\n", argv[1]);
        return 1;
    }

    printf("학번\t이름\t점수\n");
    printf("====================\n");

    // 파일에서 구조체 내용 읽기
    while (fscanf(fp, "%d %s %f", &s.id, s.name, &s.score) == 3) {
        printf("%d\t%s\t%.2f\n", s.id, s.name, s.score);
    }

    fclose(fp);
    return 0;
}

