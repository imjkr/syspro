// main.c
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

    // 파일 열기 (쓰기 모드)
    fp = fopen(argv[1], "w");
    if (fp == NULL) {
        printf("파일 열기 오류: %s\n", argv[1]);
        return 1;
    }

    printf("학번, 이름, 점수를 입력하세요: ");
    
    // 입력 검사
    if (scanf("%d %s %hd", &s.id, s.name, &s.score) != 3) {
        printf("입력 오류: 학번, 이름, 점수 모두 입력해야 합니다.\n");
        fclose(fp);
        return 1;
    }

    // 파일에 저장
    fprintf(fp, "%d %s %hd\n", s.id, s.name, s.score);
    printf("학생 정보가 '%s' 파일에 저장되었습니다.\n", argv[1]);

    fclose(fp);
    return 0;
}

