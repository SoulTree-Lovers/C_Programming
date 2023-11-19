#include <stdio.h>

void reverse(int* start, int* end) {
    int temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    reverse(arr, arr+len-1);

    for (int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}