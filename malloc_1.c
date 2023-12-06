// 성적 처리 프로그램을 작성한다고 하자. 사용자한테 학생이 몇 명인지를 물어보고
// 적절한 동적 메모리를 할당한다. 사용자로부터 성적을 받아서 저장하였다가 다시 출력한다.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *list;
    int i, students;

    printf("학생 수: ");
    scanf("%d", &students);

    list = (int *) malloc (students * sizeof(int));

    if (list == NULL) {
        printf("동적 메모리 할당 실패.\n");
        exit(1);
    }

    for (i = 0; i < students; i++) {
        printf("학생 %d의 성적: ", i + 1);
        scanf("%d", &list[i]);
    }

    printf("============================\n");

    for (i = 0; i < students; i++) {
        printf("학생 %d의 성적: %d\n", i + 1, list[i]);
    }

    printf("============================\n");
    free(list);

    return 0;
}