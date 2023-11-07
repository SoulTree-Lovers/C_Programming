#include <stdio.h>
#include <math.h>


double ln(double x) {
    if (x <= 0.5 || x >= 2) {
        printf("Error: x must be between 0.5 and 2\n");
        return 0;
    }
    
    double approximation = 0;
    double term = x - 1;
    int n = 1;
    
    const double EPSILON = 0.0001;
    const int MAX_ITERATIONS = 1000;
    
     double prev_approximation = 0;
    while (fabs(approximation - prev_approximation) > EPSILON && n < MAX_ITERATIONS) {
        prev_approximation = approximation;
        approximation += term;
        term *= -(x - 1) / n; 
        n++;
    }
    
    return approximation;
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
