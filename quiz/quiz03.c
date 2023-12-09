#include <stdio.h>
#define SIZE 100

int removeCharacters(char* s, char c) {
    int count = 0; // 삭제된 문자 개수
    char* p = s; // 문자열의 시작 주소를 저장
    while (*s != '\0') { // 문자열의 끝까지 반복
        if (*s != c && *s != c - 32 && *s != c + 32) { // 대소문자 구분 없이 문자가 같지 않으면
            *p++ = *s; // 문자열의 시작 주소에 문자를 저장하고 시작 주소를 1 증가
        } else { // 문자가 같으면
            count++; // 삭제된 문자 개수를 1 증가
        }
        s++; // 문자열의 주소를 1 증가
    }
    *p = '\0'; // 문자열의 끝에 null 문자 저장
    return count;
}

int main() {
    char str[SIZE]; // 문자열을 저장할 배열
    char c; // 삭제할 문자
    printf("문자열을 입력하세요: "); 
    gets(str); // 문자열 입력 (공백 포함 한줄 입력)
    printf("삭제할 문자를 입력하세요: ");  
    scanf("%c", &c);
    int n = removeCharacters(str, c);
    printf("수정된 문자열: %s\n", str);
    printf("삭제된 문자들의 개수: %d\n", n);
    return 0;
}

