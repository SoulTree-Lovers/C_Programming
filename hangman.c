#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int check(char s[], char a[], char ch) {
    int i;
    for (i = 0; s[i] != '\0'; i++) { 
        if (s[i] == ch)
            a[i] = ch;
    }
    if (strcmp(s, a) == 0) 
        return 1; // 정답과 일치하는지를 검사
    else 
        return 0; 
}

void generate_underline(char input[], char output[]) {
    int i;
    for (i = 0; input[i] != '\0'; i++) { 
        if (input[i] != ' ')
            output[i] = '_'; 
        else
            output[i] = ' '; 
    }
    output[i] = '\0';     
}

int main(void) {
    char solution[100];
    char solution_pool[5][100] = {
        "book", 
        "boy", 
        "computer", 
        "lanuguage", 
        "rain"
    };
    char answer[100]; char ch;
    int try_count = 0;

    srand((unsigned)time(NULL));

    strcpy(solution, solution_pool[rand() % 5]); 
    generate_underline(solution, answer);

    while (1) {
        printf("문자열을 입력하시오: %s \n", answer); 
        printf("글자를 추측하시오: ");
        ch = getchar();
        if (check(solution, answer, ch) == 1)
            break;
        fflush(stdin); // 줄바꿈 문자 제거 
        try_count++;
        if (try_count > 5)
            break; 
    }

    return 0; 
}