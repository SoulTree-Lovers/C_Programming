#include <stdio.h>

int amount = 100000;

int login(int pin) {
    int pin_num = 1234;
    return pin == pin_num ? 1 : 0;
}

void deposit(int money) {
    amount += money;
}

void withdraw(int money) {
    amount -= money;
}

int main() {
    
    int pin;
    int pin_num = 1234;
    printf("PIN 번호를 입력하세요: ");
    scanf("%d", &pin);

    if (!login(pin)) {
        printf("로그인 실패\n");
        return 0;
    }

    printf("안녕하세요!\n");
    
    printf("1. 입금\n2. 출금\n");
    int menu, money;
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        printf("입금할 금액을 입력하세요: ");
        scanf("%d", &money);
        deposit(money);
        printf("입금이 완료되었습니다. 현재 잔액: %d\n", amount);
        break;
    case 2:
        printf("출금할 금액을 입력하세요: ");
        scanf("%d", &money);
        withdraw(money);
        printf("출금이 완료되었습니다. 현재 잔액: %d\n", amount);
    default:
        break;
    }


    return 0;
}