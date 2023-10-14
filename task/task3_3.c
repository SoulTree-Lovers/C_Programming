#include <stdio.h>
#include <string.h>

// 함수 선언
int reverseNumber(int);
int reversedSum(int, int);

int main() {
    // a, b 선언 및 할당
    int a, b;
    scanf("%d %d", &a, &b);
    
    // reversedSum() 함수 호출
    int result = reversedSum(a, b);
    
    // 결과 출력
    printf("result: %d\n", result);

    return 0;
}

// 정수 뒤집기
int reverseNumber(int num) {
    int reversed = 0;

    // 맨 뒷 자리(일의 자리)부터 순서대로 10씩 곱하며 자리 바꾸기
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    // 뒤집어진 정수 반환
    return reversed;
}

// 뒤집은 정수 더하기
int reversedSum(int a, int b) {
    // 뒤집어진 정수 구하기
    int reversedA = reverseNumber(a);
    int reversedB = reverseNumber(b);
    
    // 출력 테스트
    // printf("reversedA: %d\n", reversedA);
    // printf("reversedB: %d\n", reversedB);

    // 뒤집은 정수 덧셈 결과 반환
    return reversedA + reversedB;
}