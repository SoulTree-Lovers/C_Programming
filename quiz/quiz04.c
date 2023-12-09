/* 텍스트 파일로부터 각 줄에 있는 단어를 읽고, 각 단어를 위해 동적으로 메모리를 할당한
 후 화면에 출력하는 프로그램을 작성하세요. */
// 1."words.txt" 파일을 열고 각 줄에 있는 단어를 읽어야 합니다.(fgets)
// 2.각 단어를 저장하기 위해 동적으로 메모리를 재할당해야 합니다.(realloc)
// 3.모든 단어를 읽은 후, 각 단어를 화면에 출력하세요.(printf)
// 4.프로그램이 끝나기 전에 모든 동적으로 할당된 메모리를 해제하세요.(free)
// 5.파일이 존재하지 않거나, 메모리 할당이 되지 않았을 때 적절한 예외처리를 해주세요.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        perror("파일 열기 에러");
        return 1;
    }

    char** words = NULL; // 단어 저장된 동적 메모리 가리키는 더블포인터 변수
    int num_words = 0; // 파일 안에 있는 단어 개수
    char buffer[MAX_WORD_LENGTH];  // 파일로부터 읽어들인 문자열을 저장할 임시 변수

    // 파일에서 한 줄씩 읽기
    while (fgets(buffer, MAX_WORD_LENGTH, file)) {
        char* word = strtok(buffer, " \n");
        // 단어를 저장하기 위해 동적 메모리 할당
        words = (char**)realloc(words, sizeof(char*) * (num_words+1)); // 메모리 재할당
        words[num_words] = (char*)malloc(sizeof(char) * (strlen(word) + 1)); // 단어 길이만큼 메모리 할당
        words[num_words] = strdup(word); // strdup는 문자열 복사하는 함수
        num_words++; // 단어 개수 증가
        word = strtok(NULL, " \n"); // 다음 단어 읽기
    }
    // 단어 출력하기
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }

    // 메모리 해제하기
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return 0;
}