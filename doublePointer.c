#include <stdio.h>

void set_pointer(char** q) {
    *q = "Hello World!";
}

int main() {
    char* p;
    set_pointer(&p);
    printf("%s\n", p);
    return 0;
}