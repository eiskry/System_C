#include <stdio.h>
#include <stdlib.h>

void plus(int *a, int p, int q)
{
  *a = p + q;
}

int main(int argc, char *argv[])
{
  int x, y, answer;
  int *answerp;

  if (argc != 3) {
    fprintf(stderr, "Missing argument\n");
    return 1;
  }

  x = atoi(argv[1]);
  y = atoi(argv[2]);

  answerp = &answer;
  plus(answerp, x, y);

  printf("%d + %d = %d\n", x, y, answer);

  return 0;
}