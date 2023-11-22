#include <stdio.h>

/*
    <은행 입출금 시스템 구현>
    1. PIN 번호를 통해 로그인
    2. 계좌정보를 구조체로 선언
    3. 메뉴는 [실행 결과]를 확인
*/

void printService() {
    printf("---------- ATM 서비스 ----------\n");
    printf("1. 잔액 확인\n");
    printf("2. 현금 인출\n");
    printf("3. 현금 입금\n");
    printf("4. 종료\n");
    printf("------------------------------\n");
}

struct account
{
    char name[100];
    int id;
    int balance;
};


int main() {
    struct account myacc = {"Kim", 123456, 100000};
    int pin;
    printf("PIN 번호 입력: ");
    scanf("%d", &pin);

    if (pin != 1234) {
        printf("PIN 번호가 틀렸습니다.\n");
        return 0;
    }

    
    int menu;
    char answer;
    
    while (1) {
        printService();
        printf("메뉴 선택: ");
        scanf("%d", &menu);
        if (menu == 1) {
            printf("잔액: %d\n", myacc.balance);
        } else if (menu == 2) {
            int money;
            printf("인출할 금액: ");
            scanf("%d", &money);
            if (money > myacc.balance) {
                printf("잔액이 부족합니다.\n");
            } else {
                myacc.balance -= money;
                printf("인출 후 잔액: %d\n", myacc.balance);
            }
        } else if (menu == 3) {
            int money;
            printf("입금할 금액: ");
            scanf("%d", &money);
            myacc.balance += money;
            printf("입금 후 잔액: %d\n", myacc.balance);
        } else if (menu == 4) {
            printf("ATM 서비스를 종료합니다.\n");
            break;
        } else {
            printf("잘못된 메뉴입니다.\n");
        }

        printf("다른 거래를 하시겠습니까? (y/n): ");
        scanf(" %c", &answer);

        if (answer == 'n') {
            printf("ATM 서비스를 종료합니다.\n");
            break;
        } else if (answer == 'y') {
            printf("다른 거래를 시작합니다.\n");
        } else {
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}


