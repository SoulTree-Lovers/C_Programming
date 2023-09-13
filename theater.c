#include <stdio.h>

int main() {
    int row, col;

    while (1) {
        printf("좌석의 행을 입력하세요: ");
        scanf("%d", &row);
        
        if (row < 1 || row > 10){
            printf("처음부터 다시 입력해주세요.\n");
            continue;
        }

        printf("좌석의 열을 입력하세요: ");
        scanf("%d", &col);

        if (col < 1 || col > 20){
            printf("처음부터 다시 입력해주세요.\n");
            continue;
        }

        if (row < 6) {
            printf("해당 좌석은 15,000원입니다.\n");
            break;
        } else {
            printf("해당 좌석은 10,000원입니다.\n");
            break;
        }
    }
    
}