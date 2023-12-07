#include <stdio.h>
#include <stdlib.h>

// 파일에서 숫자를 읽어 동적 배열에 저장하는 함수
void readNumbers(const char* fileName, int** numbers, int* size) {
    FILE* fp;
    int num;
    int count = 0;

    if ((fp = fopen(fileName, "r")) == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
        exit(1);
    }

    while (fscanf(fp, "%d", &num) == 1) {
        count++;
        *numbers = (int*)realloc(*numbers, sizeof(int) * count);
        (*numbers)[count - 1] = num;
    }

    fclose(fp);

    if (count == 0) {
        fprintf(stderr, "파일에 숫자가 없습니다.\n");
        exit(1);
    }

    *size = count;
}

int main() {
    char fileName[100];
    int* numbers = NULL;
    int size = 0;
    double sum = 0.0;
    double average;

    printf("파일 이름: ");
    scanf("%99s", fileName);

    readNumbers(fileName, &numbers, &size);

    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }

    average = sum / size;

    printf("평균: %.2lf\n", average);

    free(numbers);

    return 0;
}