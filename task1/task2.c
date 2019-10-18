#include <stdio.h>

int main(void)
{
  char str1[100], str2[100];
  int i, j,c;

  scanf("%s", str1);

  i = 0;
  j = 0;
  c = 0;
 for (i=0;str1[i] != '\0';i++) {
     c=i+1;
     }

 printf("%d\n", c);
 
 i = 0;
  j = 0;
 while (str1[i] != '\0') {
      str2[j] = str1[c-i];
      j++;
    i++;
  }
  str2[c+1] = '\0';


  printf("%s\n", str2);

  return 0;
}