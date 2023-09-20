#include <stdio.h>

int main() {
    char name1[10], name2[10], name3[10];
    int age1, age2, age3;
    float height1, height2, height3;


    printf("이름1, 나이1, 키1을 입력하세요: ");
    scanf("%s %d %f", name1, &age1, &height1);

    printf("이름2, 나이2, 키2을 입력하세요: ");
    scanf("%s %d %f", name2, &age2, &height2);

    printf("이름3, 나이3, 키3을 입력하세요: ");
    scanf("%s %d %f", name3, &age3, &height3);

    
    
    float avg_age, avg_height;
    avg_age = (age1 + age2 + age3) / 3;
    avg_height = (height1 + height2 + height3) / 3;

    printf("3명의 평균 나이: %lf, 평균 키: %lf \n", avg_age, avg_height);

    if (age1 > avg_age) {
        printf("평균 나이보다 많은 사람: %s \n", name1);
    }

    if (age2 > avg_age) {
        printf("평균 나이보다 많은 사람: %s \n", name2);
    }

    if (age3 > avg_age) {
        printf("평균 나이보다 많은 사람: %s\n", name3);
    }

    if (height1 > avg_height) {
        printf("평균 키보다 큰 사람: %s\n", name1);
    }

    if (height2 > avg_height) {
        printf("평균 키보다 큰 사람: %s\n", name2);
    }

    if (height3 > avg_height) {
        printf("평균 키보다 큰 사람: %s\n", name3);
    }
}