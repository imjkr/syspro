#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 파일을 복사하는 메인 함수
int copy_file(const char *source_path, const char *dest_path, int mode) {
    FILE *source_file, *dest_file;
    int ch;

    // 원본 파일 열기 (읽기 모드)
    source_file = fopen(source_path, "r");
    if (source_file == NULL) {
        fprintf(stderr, "오류: 원본 파일 '%s'을(를) 열 수 없습니다.\n", source_path);
        return 0; // 실패
    }

    // 대상 파일 열기 (쓰기 모드)
    dest_file = fopen(dest_path, "w");
    if (dest_file == NULL) {
        fprintf(stderr, "오류: 대상 파일 '%s'을(를) 열 수 없습니다.\n", dest_path);
        fclose(source_file); // 원본 파일 닫기
        return 0; // 실패
    }

    // 파일 내용 읽고 쓰기
    while ((ch = fgetc(source_file)) != EOF) {
        int output_ch = ch;

        switch (mode) {
            case 0:
                // mode 0: 원본과 동일하게 복사 (변환 없음)
                break;
            case 1:
                // mode 1: 모든 대문자를 소문자로 변환
                output_ch = tolower(ch);
                break;
            case 2:
                // mode 2: 모든 소문자를 대문자로 변환
                output_ch = toupper(ch);
                break;
            default:
                // 예기치 않은 모드 (일반 복사 처리)
                break;
        }
        
        // 대상 파일에 문자 쓰기
        if (fputc(output_ch, dest_file) == EOF) {
            fprintf(stderr, "오류: 대상 파일에 쓰는 중 오류가 발생했습니다.\n");
            fclose(source_file);
            fclose(dest_file);
            return 0; // 실패
        }
    }

    // 파일 닫기
    fclose(source_file);
    fclose(dest_file);

    return 1; // 성공
}

int main(int argc, char *argv[]) {
    int mode;

    // 1. 명령줄 인수 개수 확인 (프로그램 이름, 모드, 원본 파일, 대상 파일 => 총 4개)
    if (argc != 4) {
        printf("사용법: %s <mode> <source.txt> <destination.txt>\n", argv[0]);
        printf("  <mode>:\n");
        printf("    0: 원본과 동일하게 복사\n");
        printf("    1: 모든 대문자를 소문자로 변환하여 복사\n");
        printf("    2: 모든 소문자를 대문자로 변환하여 복사\n");
        return 1; // 에러 코드 반환
    }

    // 2. 모드(mode) 값 파싱
    if (strcmp(argv[1], "0") == 0) {
        mode = 0;
    } else if (strcmp(argv[1], "1") == 0) {
        mode = 1;
    } else if (strcmp(argv[1], "2") == 0) {
        mode = 2;
    } else {
        fprintf(stderr, "오류: 알 수 없는 모드입니다. (0, 1, 2 중 하나를 사용하세요.)\n");
        return 1;
    }

    // 3. 파일 복사 실행
    if (copy_file(argv[2], argv[3], mode)) {
        printf("파일 복사 성공. (모드: %d, 원본: %s, 대상: %s)\n", mode, argv[2], argv[3]);
    } else {
        fprintf(stderr, "파일 복사 실패.\n");
        return 1;
    }

    return 0;
}
