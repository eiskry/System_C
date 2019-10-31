#include <stdio.h>
#include <string.h>

int main(void)
{
  char str1[100], str2[100];
  int i, j;

  scanf("%s", str1);
  scanf("%s", str2);

  
  i=0;
  j=0;
  
  for (i = 0; i < strlen(str1); i++)
    if (strchr(str2, str1[i]) != NULL)
      putc(str1[i], stdout);



  return 0;
}
