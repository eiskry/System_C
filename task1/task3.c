#include <stdio.h>

int main(void)
{
     char str1[100], str2[100],str3[100];
  int i, j;

   scanf("%s", str1);
    scanf("%s", str2);

  i = 0;
  j = 0;
  while (str2[i] != '\0') {
    if (str1[i] = str2[i]) {
      str3[j] = str2[i];
      j++;
    }
    i++;
  }

   str3[j] = '\0';

  printf("%s\n", str3);

  return 0;
}

