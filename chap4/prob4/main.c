// main.c
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[]) {
    FILE *fp;
    Student s;

    // 명령줄 인자 확인
    if (argc != 2) {
        printf("사용법: %s <파일이름>\n", argv[0]);
        return 1;
    }

    // 파일 열기 (쓰기 모드 w → 새로 작성)
    fp = fopen(argv[1], "w");
    if (fp == NULL) {
        printf("파일 열기 오류: %s\n", argv[1]);
        return 1;
    }

    printf("학번\t이름\t점수\n");

    // 여러 명 입력 (Ctrl + D로 종료)
    while (scanf("%d %s %f", &s.id, s.name, &s.score) == 3) {
        fprintf(fp, "%d %s %.2f\n", s.id, s.name, s.score);
    }

    fclose(fp);
    printf("학생 정보가 '%s' 파일에 저장되었습니다.\n", argv[1]);

    return 0;
}

