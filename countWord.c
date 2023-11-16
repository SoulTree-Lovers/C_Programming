#include <stdio.h>
#include <ctype.h>

int count_word(char* str) {
    int count = 0;
    int i;
    for (i = 0; *(str+i) != '\0'; i++) {
        if (isalpha(*(str+i)) && !isalpha(*((str+i)+1))) {
            count++;
        }
    }
    return count;
}

int main() {
    int wc = count_word("Hello, world!");
    printf("단어의 개수: %d\n", wc);
    return 0;
}