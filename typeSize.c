#include <stdio.h>

int main(){
    int x;

    printf("변수 x의 크기: %lu \n", sizeof(x));
    printf("char의 크기: %lu \n", sizeof(char));
    printf("int의 크기: %lu \n", sizeof(int));
    printf("short의 크기: %lu \n", sizeof(short));
    printf("long의 크기: %lu \n", sizeof(long));
    printf("float의 크기: %lu \n", sizeof(float));
    printf("double의 크기: %lu \n", sizeof(double));
    
    return 0;
}