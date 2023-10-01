#include <stdio.h>

int main() {
    int bacteria = 10; // 초기 세균 마리 수 선언
    int rate = 4; // 1시간 당 증식률
    int hour = 1; // 시간 변수 선언
    
    
    while (1) {
        // 7시간이 지나면 while문 종료
        if (hour > 7) {
            break;
        }

        // 세균 증식
        bacteria *= rate;

        // 한 시간 경과
        hour++; 
    }

    printf("7시간 후의 세균의 수는 %d마리입니다.\n", bacteria);

    return 0;
}