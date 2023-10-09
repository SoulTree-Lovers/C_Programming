#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 난수 초기화
    srand(time(NULL));

    // 연산자 배열과 연산자 선택 변수
    char operators[] = {'+', '-', '*', '/'};
    char selectedOperator;

    // 무한 루프
    while (1) {
        // 무작위로 연산자 선택
        int operatorIndex = rand() % 4;
        selectedOperator = operators[operatorIndex];

        // 무작위로 피연산자 선택
        int operand1 = rand() % 100; // 0부터 99까지의 난수
        int operand2 = rand() % 100;

        // 수학 문제 생성 및 출력
        printf("수학 문제: %d %c %d = ? (q 입력 시 종료): ", operand1, selectedOperator, operand2);

        // 사용자 입력 받기
        char userInput[10];
        scanf("%s", userInput);

        // 'q' 입력 시 종료
        if (userInput[0] == 'q') {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        // 사용자 입력을 정수로 변환하여 계산
        int userAnswer = atoi(userInput);
        int correctAnswer;

        // 정답 계산
        switch (selectedOperator) {
            case '+':
                correctAnswer = operand1 + operand2;
                break;
            case '-':
                correctAnswer = operand1 - operand2;
                break;
            case '*':
                correctAnswer = operand1 * operand2;
                break;
            case '/':
                correctAnswer = operand1 / operand2;
                break;
            default:
                printf("올바르지 않은 연산자입니다.\n");
                continue; // 루프의 처음으로 돌아감
        }

        // 답 검증 및 출력
        if (userAnswer == correctAnswer) {
            printf("정답입니다!\n");
        } else {
            printf("틀렸습니다. 정답은 %d 입니다.\n", correctAnswer);
        }
    }

    return 0;
}
