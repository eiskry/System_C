#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char str1[100],str2[100];
  int i;
  int n, tmp;
  int digit;

  scanf("%s", str1);

  //　入力str1をint型に変換
  n = atoi(str1);
  tmp = n;
  digit = 0;

  //  入力の整数の桁数を求める
  do {
    tmp /= 10;
    digit++;
  } while (tmp > 0);

  //　str2にstr1の最後の要素から順に格納
  for(i=0;i<digit;i++){
    str2[i]=str1[digit-1-i];
  }
  str2[digit+1] = '\0';

  //　str2の表示
  printf("%s\n", str2);

  return 0;
}
