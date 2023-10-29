#include <stdio.h>
#include <math.h>

double ln(double x) {
    if (x <= 0.5 || x >= 2) { // 에러 메시지 출력
        printf("에러: x값은 0.5이상 2이하인 수여야 합니다.\n");
        return 0;
    }
    const double epsilon = 0.0001; // 최소 오차값
    const int MAX_ITERATIONS = 1000; // 최대 반복수

    double result = 0; // 결과값 저장
    double term = x - 1; // 현재 항 저장
    double prev_term = 0; // 이전 항 저장
    double curr_val = 0; // 현재 오차값 저장

    int n = 1; // 분모값
    int prev_n = 1; // 전항의 분모값

    while (n < MAX_ITERATIONS) {
        // 오차 구하기
        if (term >= prev_term) {
            curr_val = fabs(term - prev_term);
        } else {
            curr_val = fabs(prev_term - term);
        }

        if (curr_val <= epsilon) break; // 오차가 0.0001보다 작으면 반복문 종료
        
        result += term; // 결과값에 현재 항값 더하기
        prev_term = term; // 현재 항을 이전 항에 저장
        n++; // 분모 1증가 
        term *= -(x - 1) / n * prev_n; // 현재 항 업데이트
        prev_n++; // 다시 곱할 값 1 증가
    }
    return result; // 결과값 반환
}

int main() {
    double x; // x값 선언
    do {
        printf("x값 입력(0.5 <= x <= 2): ");
        scanf("%lf", &x); // x 값 저장
    } while (x <= 0.5 || x >= 2); // x 값이 범위 내에 있지 않으면 다시 입력받기
    printf("ln(%lf) = %lf\n", x, ln(x)); // 결과 출력
    return 0;
}
