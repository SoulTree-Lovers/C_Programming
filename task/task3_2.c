#include <stdio.h>

// 화면에 메뉴 출력
void disp_menu() {
    printf("1. 덧셈\n");
    printf("2. 뺄셈\n");
    printf("3. 곱셈\n");
    printf("4. 나눗셈\n");
}

// 덧셈 연산
double add(double a, double b) {
    return a + b;
}

// 뺄셈 연산
double sub(double a, double b) {
    return a - b;
}

// 곱셈 연산
double mul(double a, double b) {
    return a * b;
}

// 나눗셈 연산
double div(double a, double b) {
    return a / b;
}


int main() {
    int number; // 메뉴 번호
    double a, b; // 계산할 두 실수
    double result; // 계산 결과 저장할 변수

    disp_menu(); // 메뉴 화면에 출력

    // 메뉴 번호 입력받기
    printf("번호를 선택하세요: ");
    scanf("%d", &number);

    // 첫 번째 실수 입력받기
    printf("첫 번째 실수를 입력하세요: ");
    scanf("%lf", &a);

    // 두 번째 실수 입력받기
    printf("두 번째 실수를 입력하세요: ");
    scanf("%lf", &b);
    
    // 번호에 따른 함수 호출
    switch (number)
    {
        case 1:
            result = add(a, b);
            break;

        case 2:
            result = sub(a, b);
            break;

        case 3:
            result = mul(a, b);
            break;

        case 4:
            result = div(a, b);
            break;

        default:
            printf("Unknown number %d\n", number);
            break;
    }

    // 연산 결과 출력
    printf("연산 결과: %lf\n", result);

    return 0;
}
