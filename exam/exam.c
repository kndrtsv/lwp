#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//проверяем строку на корректность
int is_valid_string(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i]) && !isspace(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char file[] = "C:/Users/user/CLionProjects/lwbop/exam/file.txt";

    //перенапрявляем ввод
    FILE *fp = freopen(file, "r", stdin);
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (strlen(buffer) == 1) {
            printf("Empty line\n");
            continue;
        }

        if (is_valid_string(buffer)) {
            printf("Correct string entered: %s\n", buffer);
        }
        else
            printf("Incorrect string entered: %s\n", buffer);;
    }

    fclose(fp);

    return 0;
}