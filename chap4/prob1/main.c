#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int ch;

    if (argc < 2) {
        while ((ch = getchar()) != EOF) {
            putchar(ch);
        }
    } else {
        for (int i = 1; i < argc; i++) {
            fp = fopen(argv[i], "r");
            if (fp == NULL) {
                perror(argv[i]);
				continue;
            }
            while ((ch = fgetc(fp)) != EOF) {
                putchar(ch);
            }
            fclose(fp);
        }
    }
    return 0;
}

