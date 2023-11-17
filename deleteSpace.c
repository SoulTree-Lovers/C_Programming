#include <stdio.h>
#define SIZE 100

void delete_space(char* str) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            for (j = i; str[j] != '\0'; j++) {
                str[j] = str[j + 1];
            }
            i--;
        }
    }
}


int main() {
    char str[SIZE];
    printf("공백이 있는 문자열을 입력하세요: ");
    gets(str);
    delete_space(str);
    printf("%s\n", str);
    return 0;
}