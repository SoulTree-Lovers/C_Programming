#include <stdio.h>

int main() {
    int i, j;

    for (i=1; i<=6; i++) {
        for (j=i; j<=6; j++) {
            if (i + j == 6) {
                printf("(%d, %d)\n", i, j);
            }
        }
    }


    return 0;
}