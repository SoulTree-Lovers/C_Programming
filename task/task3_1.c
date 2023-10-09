#include <stdio.h>
#include <math.h>

// 함수 정의
int f(int n) {
    int sum = 0; // 합을 저장할 변수 선언
    for (int i=1; i<=n; i++) {
        sum += pow(i, 2); // i를 1부터 n까지 i의 제곱만큼 sum에 더함
    }
    return sum; // 합 리턴
}

int main() {
    int n; // 사용자로부터 입력받을 정수 변수 선언

    // 정수 입력 받기
    printf("양의 정수 하나를 입력하세요: ");
    scanf("%d", &n);

    // 함수 리턴 값 출력
    printf("%d\n", f(n));

    return 0;
}
