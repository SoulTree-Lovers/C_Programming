#include <stdio.h>

int main() {
    char inputChar;
    

    while (1) {
        printf("소문자 영어를 입력하세요 ('q' 입력시 종료): ");
        scanf(" %c", &inputChar);

        if (inputChar == 'q') {
            printf("프로그램을 종료합니다.\n");
            break; // 'q'가 입력되면 루프를 종료합니다.
        }

        if (inputChar >= 'a' && inputChar <= 'z') {
            char uppercaseChar = inputChar - 'a' + 'A';
            printf("대문자로 변환: %c\n", uppercaseChar);
        } else {
            printf("올바른 소문자를 입력하세요 ('q' 입력시 종료): \n");
        }
    }

    return 0;
}
