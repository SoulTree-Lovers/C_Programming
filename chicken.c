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