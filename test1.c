#include <stdio.h>
#include <math.h>

double ln(double x) {
    if (x <= 0.5 || x >= 2) {
        printf("에러: x는 0.5 이상 2 이하인 수여야 합니다.\n");
        return 0;
    }
    double result = 0;
    double term = x - 1;
    
    int n = 1;
    const double epsilon = 0.0001;
    const int MAX_ITERATIONS = 1000;
    while (fabs(term) > epsilon && n < MAX_ITERATIONS) {
        result += term;
        term *= -(x - 1) / n;
        n++;
    }
    return result;
}

int main() {
    double x;
    do {
        printf("Enter a value for x between 0.5 and 2: ");
        scanf("%lf", &x);
    } while (x <= 0.5 || x >= 2);
    printf("ln(%lf) = %lf\n", x, ln(x));
    return 0;
}
