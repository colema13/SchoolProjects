#include <stdio.h>

int main()
{
  char name[100];
  int year;

  printf("Enter your name: ");
  scanf("%s",name);

  printf("What year were you born? ");
  scanf("%d",&year);

  int age = 2025-year;

  printf("%s, this year you turn %d.\n",name,year);

  return 0;
}
