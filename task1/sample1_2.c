#include <stdio.h>

int main(void)
{
  int n, tmp;
  int digit;

  scanf("%d", &n);

  tmp = n;
  digit = 0;

  do {
    tmp /= 10;
    digit++;
  } while (tmp > 0);

  printf("%d\n", digit);

  return 0;
}