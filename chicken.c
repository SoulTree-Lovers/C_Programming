#include<stdio.h>

int main(void)
{
   int A, B, C, X, Y;
   int price=0;
   scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

   if ((A + B)/2 > C) {
      if (X > Y) {
         price = C * 2 * Y + (X - Y) * A;
      }
      else {
         price = C * 2 * Y + (Y - X) * B;
      }
   }
   else {
      price = X * A + Y * B;
   }
   printf("%d\n", price);

   return 0;
}
// 위 코드의 반례를 해결한 아래 코드
// 반례: 10000 10000 1 6 3 => 12 
// #include <stdio.h>

// int main() {
//    int A, B, C, X, Y;
//    int sum = 0;
//    scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y);
//    if (A + B > 2 * C) {
//       int tmp = X < Y ? X : Y;
//       sum = 2 * tmp * C;
//       if (A > 2 * C) {
//          sum += 2 * C * (X - tmp);
//       }
//       else {
//          sum += A * (X - tmp);
//       }
//       if (B > 2 * C) {
//          sum += 2 * C * (Y - tmp);
//       }
//       else {
//          sum += B * (Y - tmp);
//       }
//    }
//    else {
//       sum = X * A + Y * B;
//    }
//    printf("%d\n", sum);
// }