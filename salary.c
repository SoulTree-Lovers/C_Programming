#include <stdio.h>

int main(){
    double salary;
    printf("연봉: ");
    scanf("%lf", &salary);
    printf("월급: %.2lf\n", salary/12); 
    
    return 0;
}