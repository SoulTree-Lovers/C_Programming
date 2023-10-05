#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("rand: %d\n", rand());
    
    srand(time(NULL));
    printf("srand: %d\n", rand());
}