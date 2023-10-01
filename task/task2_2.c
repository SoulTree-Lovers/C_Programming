#include <stdio.h>

int main() {
    int initialArea = 2 << 9; // 초기 면적은 2의 10제곱으로 선언
    int tempArea = 2 << 9; // 임시 면적 변수 선언
    int rate = 2; // 감소율 변수 선언
    int count = 0; // 접은 횟수 변수 선언


    while (1) {
        // 면적이 초기 면적의 100분의 1보다 작아질 경우 반복문 종료
        if (tempArea < initialArea / 100) {
            break;
        }

        // 면적 1/2로 감소
        tempArea = tempArea / rate;

        // 카운트 1 증가
        count++;
    }

    printf("종이를 %d번 접어야 원래 면적의 1/100로 줄어듭니다.\n", count);

    return 0;
}