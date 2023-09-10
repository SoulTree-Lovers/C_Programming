#include <stdio.h>

int main(){
    int x, y;
    printf("첫 번째 정수를 입력하세요: ");
    scanf("%d", &x);

    printf("두 번째 정수를 입력하세요: ");
    scanf("%d", &y);

    printf("두 수의 합: %d\n", x+y); 
    
    return 0;
}