#include <stdio.h>

int get_integer(int x, int y) {
    return x + y;
}

int main() {
    int a, b, output;

    scanf("%d %d", &a, &b);
    output = get_integer(a, b);

    printf("%d\n", output);

    return 0;
}

