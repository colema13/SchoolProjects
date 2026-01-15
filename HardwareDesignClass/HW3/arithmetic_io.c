#include <stdio.h>

int main()
{
  int num1;
  int num2;

  printf("Enter a number:");
  scanf("%d", &num1);

  printf("Enter another number:");
  scanf("%d", &num2);

  int add = num1+num2;
  int sub = num1-num2;
  int mult = num1*num2;
  int div = num1/num2;

  printf("%d + %d = %d\n", num1, num2, add);
  printf("%d - %d = %d\n", num1, num2, sub);
  printf("%d * %d = %d\n", num1, num2, mult);
  printf("%d / %d = %d\n", num1, num2, div);

  return 0;
}
