#include <stdio.h>
#include <string.h>

int main(void)
{
  char str1[100], str2[100];
  int i, j;

  //　標準入力から読み込んだ一行をstr1に格納
  scanf("%s", str1);

  //　標準入力から読み込んだ次の行をstr2に格納
  scanf("%s", str2);

  //　str1とstr2の文字を比較、同じなら出力
  for (i = 0; i < strlen(str1); i++)
    if (strchr(str2, str1[i]) != NULL)
      putc(str1[i], stdout);
    
  return 0;
}
