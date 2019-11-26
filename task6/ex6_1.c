#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n;
  int t,f;

  if (argc != 2) {
    fprintf(stderr, "Missing argument\n");
    exit(1);
  }

  n = atoi(argv[1]);

  t = n/10;
  f = n%10;

  switch (t) {
  case 2:
    printf("twenty ");
    break;
  case 3:
    printf("thirty ");
    break;
  case 4:
    printf("forty ");
    break;
  case 5:
    printf("fifty ");
    break;
  case 6:
    printf("sixty ");
    break;
  case 7:
    printf("seventy ");
    break;
  case 8:
    printf("eighty ");
    break;
  case 9:
    printf("ninty ");
    break;
  default:
    fprintf(stderr, "Invalid argument: %d\n", n);
    exit(1);
  }

  switch (f) {
   case 1:
    printf("one\n");
    break;    
  case 2:
    printf("two\n");
    break;
  case 3:
    printf("three\n");
    break;
  case 4:
    printf("four\n");
    break;
  case 5:
    printf("five\n");
    break;
  case 6:
    printf("six\n");
    break;
  case 7:
    printf("seven\n");
    break;
  case 8:
    printf("eight\n");
    break;
  case 9:
    printf("nine\n");
    break;
  default:
    fprintf(stderr, "Invalid argument: %d\n", n);
    exit(1);
  }

  return 0;
}