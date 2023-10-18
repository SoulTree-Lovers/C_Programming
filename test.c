#include <stdio.h>

double get_double() {
    int i = 10;
    return i;
}


int main() {
    int x;

    x = get_double();

    printf("%d\n", x);
    
    return 0;
}