#include <stdio.h>
#define LIGHTSPEED 300000.000000
#define DISTANCE 149600000.000000

int main(void)
{
    double time; // 시간을 나타내는 변수

    time = DISTANCE / LIGHTSPEED; // 거리를 빛의 속도로 나눈다. 
    time = time / 60.0; // 초를 분으로 변환한다.

    printf("도달 시간은 %f초\n", time); // 시간을 출력한다.

    return 0; 
}