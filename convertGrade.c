#include <stdio.h>

void convert(double* grades, double* scores, int size) {
    int i;
    for (i=0; i<size; i++) {
        *scores = *grades / 4.5 * 100;
        scores++;
        grades++;
    }
}

int main() {
    double grades[10] = {4.3, 4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 0.0};
    double scores[10];

    convert(grades, scores, 10);

    for (int i = 0; i < 10; i++) {
        printf("%.2lf ", scores[i]);
    }
    printf("\n");
}