#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char str1[100],str2[100];
  int i;
  int n, tmp;
  int digit;

  scanf("%s", str1);

  //change to int
  n = atoi(str1);
  tmp = n;
  digit = 0;

  do {
    tmp /= 10;
    digit++;
  } while (tmp > 0);
 
  // printf("%d\n", digit);

 
  for(i=0;i<digit;i++){
    str2[i]=str1[digit-1-i];
  }
  str2[digit+1] = '\0';

  printf("%s\n", str2);

  return 0;
}
