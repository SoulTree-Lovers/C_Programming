#include <stdio.h>

void seongjuk(int* student, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(student+i);
    }
    double average = (double)sum / size;
    printf("학생들의 평균 점수는 %.2lf입니다.\n", average);
}
    
int main() {
    int student[10] = {90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
    seongjuk(student, 10);
    return 0;
}