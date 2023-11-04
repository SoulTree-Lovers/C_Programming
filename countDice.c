#include <stdio.h>

int main() {
    int dice[6] = {0, 0, 0, 0, 0, 0};
    int i;
    int num;

    for (i = 0; i < 10; i++) {
        scanf("%d", &num);
        dice[num - 1]++;
    }

    for (i = 0; i < 6; i++) {
        printf("%d: %d\n", i + 1, dice[i]);
    }

    return 0;
}