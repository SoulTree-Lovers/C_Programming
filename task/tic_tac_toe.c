#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool checkExist(char board[3][3], int x, int y);
bool checkWin(char board[3][3], char symbol);


int main() {
    char board[3][3];
    int x, y, k, i;

    // 보드 초기화
    for (x = 0; x < 3; x++) {
        for (y = 0; y < 3; y++) {
            board[x][y] = ' ';
        }
    }

    // 랜덤 시드 설정
    srand(time(NULL));

    // 사용자로부터 위치를 입력받아 보드에 표시
    for (k = 0; k < 9; k++) {
        // 사용자 차례
        printf("사용자의 차례 - (x, y) 좌표: ");
        scanf("%d %d", &x, &y);

        if (checkExist(board, x, y) == true || x < 0 || x >= 3 || y < 0 || y >= 3) {
            printf("이미 놓여져 있습니다. 다른 곳에 놓아주세요.\n");
            k--; // 현재 차례를 다시 할 수 있도록 카운트 감소
            continue;
        }
        
        board[x][y] = 'X'; // 사용자 기호로 표시

        for (i = 0; i < 3; i++) {
            printf("---|---|--- \n");
            printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        }
        printf("---|---|--- \n");

        if (checkWin(board, 'X')) {
            printf("사용자가 이겼습니다!\n");
            return 0;
        }

        // 컴퓨터 차례
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while (checkExist(board, x, y) == 1);

        printf("컴퓨터의 차례 - (%d, %d)\n", x, y);
        board[x][y] = 'O'; // 컴퓨터 기호로 표시

        for (i = 0; i < 3; i++) {
            printf("---|---|--- \n");
            printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        }
        printf("---|---|--- \n");

        if (checkWin(board, 'O')) {
            printf("컴퓨터가 이겼습니다!\n");
            return 0;
        }
    }
    printf("게임이 비겼습니다!\n");
    return 0;
}

bool checkExist(char board[3][3], int x, int y) {
    if (board[x][y] != ' ') // 빈 공간이 아닌 경우
        return true;
    else  // 빈 공간
        return false;
}

bool checkWin(char board[3][3], char symbol) {
    // 가로 및 세로 확인
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return true;
        }
        if (board[0][i] == symbol && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return true;
        }
    }

    // 대각선 확인
    if (board[0][0] == symbol && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return true;
    }
    if (board[0][2] == symbol && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return true;
    }

    return false;
}