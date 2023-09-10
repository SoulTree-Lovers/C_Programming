#include <stdio.h>

int main(){
    double w, h, area, perimeter;

    printf("가로: ");
    scanf("%lf", &w);

    printf("세로: ");
    scanf("%lf", &h);
    
    area = w * h;
    perimeter = 2 * (w+h);
    
    printf("area: %.1lf, perimeter: %.1lf\n", area, perimeter);

    return 0;
}