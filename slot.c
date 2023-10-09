#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 시뮬레이션 횟수 설정
    int simulations = 100; 

    // 랜덤 시드 설정
    srand(time(NULL));

    int games_played = 0; // 총 게임 횟수
    int winnings = 0; // 이긴 게임 횟수

    // 시뮬레이션 루프
    for (int i = 0; i < simulations; i++) {
        int money = 50; // 초기 자본
        int goal = 250; // 목표 금액

        while (money > 0 && money < goal) {
            games_played++;
            double random = (double)rand() / RAND_MAX; // 0에서 1 사이의 난수 생성

            if (random < 0.5) { // 0.5의 확률로 이기는 경우
                money++; // 1달러 획득
            } else {
                money--; // 1달러 손해
            }
        }

        if (money >= goal) {
            winnings++;
        }
    }

    printf("100번 플레이 중 %d번 성공\n", winnings);

    return 0;
}
