// Assignment 5 - 음식점 주문 시스템
/*
어느 중국 음식점에서는 음식 주문을 효율적으로 처리하기 위해 음식의 첫 글자를 이용한 시스템을
사용합니다. 주문 문자열을 분석하고, 주문 전표 및 매출 전표를 출력하는 프로그램을 작성하세요.
(배열과 포인터 사용)
기본 조건:
• 식당에는 다음과 같은 메뉴가 있습니다:
• 우동 (U) : 7000원
• 짜장면 (Z) : 8000원
• 탕수육 (T) : 12000원
• 사용자는 메뉴 항목의 문자와 수량을 이어서 입력합니다 (예: 'U3Z2T1').
• 프로그램은 주문을 분석하여 각 메뉴의 수량과 총 비용을 계산합니다.
• 사용자가 'X'를 입력하면 프로그램이 종료됩니다.
요구 사항:
1.메뉴 배열 구현: 메뉴 항목과 가격과 수량을 저장할 수 있는 적절한 배열을 구현합니다.
2.주문 입력: 사용자로부터 주문 문자열을 입력 받습니다.
3.주문 분석 및 처리: 주문 문자열을 분석하여 각 메뉴 항목의 수량을 결정하고, 총 비용을 계산합니다.
4.결과 출력: 각 메뉴 항목의 수량과 총 비용을 출력합니다.
5.오류 처리: 잘못된 입력이 있을 경우 적절한 오류 메시지를 출력하고 프로그램을 종료합니다
*/

#include <stdio.h>
#include <ctype.h>

char menuItems[] = {'U', 'Z', 'T'};
const char* menuNames[] = {"우동", "짜장면", "탕수육"};
int prices[] = {7000, 8000, 12000};
int quantities[] = {0, 0, 0};

int processReceipts(char* order) {
    // 주문을 분석하여 각 메뉴의 수량 결정 및 총 비용 계산
    for (int i = 0; *(order+i) != '\0'; i++) {
        if (isalpha(*(order+i))) {
            for (int j = 0; j < 3; j++) {
                if (*(order+i) == menuItems[j]) {
                    quantities[j] += *(order+i+1) - '0';
                }
            }
        }
    }
    // 주문이 하나도 담겨있지 않은 경우 예외처리
    if (quantities[0] == 0 && quantities[1] == 0 && quantities[2] == 0) {
        return 1;
    }

    // 주문의 길이가 6이 아닌 경우
    if (sizeof(order) != 6) {
        return 1;
    }

    // 주문에 U, Z, T가 아닌 다른 문자가 들어있는 경우
    for (int i = 0; *(order+i) != '\0'; i++) {
        if (isalpha(*(order+i))) {
            if (*(order+i) != 'U' && *(order+i) != 'Z' && *(order+i) != 'T') {
                return 1;
            }
        }
    }

    // 주문이 정상적으로 처리된 경우
    return 0;
}

int main() {
    char order[100]; // 주문 문자열
    int error = 0; // 오류 발생 여부

    // 주문 입력
    while (1) {
        printf("주문을 입력하세요(예: 'U3Z4T1', 종료하려면 'X' 입력): ");
        scanf("%s", order);
        if (order[0] == 'X') {
            break;
        }
        error = processReceipts(order);
        break;
    }

    // 오류가 발생한 경우
    if (error == 1) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }
    
    // 주문 내역 출력
    printf("주문 내역:\n");
    int i;
    for (i = 0; i < 3; i++) {
        printf("%s: %d그릇 - %d원\n", menuNames[i], quantities[i], prices[i] * quantities[i]);
    }

    // 총 비용 계산
    int total = 0;
    for (i = 0; i < 3; i++) {
        total += prices[i] * quantities[i];
    }

    printf("총 비용: %d원\n", total); // 총 비용 출력
    return 0;
}