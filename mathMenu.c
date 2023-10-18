#include <stdio.h>

double add(double, double);
double sub(double, double);
double mul(double, double);
double div(double, double);
void disp_menu();

int main() {

    while (1) {
        double x, y;
        int menu;
        int quit = 0;
    
        printf("실수 두 개를 입력하세요: ");
        scanf("%lf %lf", &x, &y);
        
        printf("메뉴 번호를 입력하세요: \n");
        disp_menu();
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("result: %lf", add(x, y));
                break;
            case 2:
                printf("result: %lf", sub(x, y));
                break;
            case 3:
                printf("result: %lf", mul(x, y));
                break;
            case 4:
                printf("result: %lf", div(x, y));
                break;
            case 5:
                printf("Quit\n");
                quit = 1;
                break;
            default: 
                perror("Invalid menu");
                break;
        }
        if (quit) break;

        printf("\n");
    }

    return 0;
}


double add(double x, double y) {
    return x + y;
}

double sub(double x, double y) {
    return x - y;
}

double mul(double x, double y) {
    return x * y;
}

double div(double x, double y) {
    return x / y;
}

void disp_menu() {
    printf("1. add\n");
    printf("2. sub\n");
    printf("3. mul\n");
    printf("4. div\n");
    printf("5. quit\n");
}