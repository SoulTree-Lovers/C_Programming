#include <stdio.h>

void askBiman(int height, int weight) {
    double bmi = ((double) weight / (((double)height / 100) * ((double)height / 100))) ;
    printf("bmi: %lf\n", bmi);

    if (bmi < 18.5) {
        printf("저체중\n");
    } else if (bmi < 23) {
        printf("정상체중\n");
    } else if (bmi < 25) {
        printf("과체중\n");
    } else if (bmi < 30) {
        printf("경도비만\n");
    } else  {
        printf("고도비만\n");
    }

}

int main() {
    int height[10];
    int weight[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &height[i]);
        scanf("%d", &weight[i]);

        askBiman(height[i], weight[i]);
    }
    
    

    return 0;
}