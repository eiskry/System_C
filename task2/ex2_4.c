#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int ch,n,count,i,ci;
  char str[1000];
  FILE *sfp;

  /* コマンドライン引数が2つ指定されているかどうか確認する */
  if (argc != 3) {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }

  

  if ((sfp = fopen(argv[1], "r")) == NULL) { /* コピー元ファイルのオープン */
    fprintf(stderr, "Can't open %s\n", argv[1]);
    return 1;
  }

  n=atoi(argv[2]);

  while ((ch = fgetc(sfp)) != EOF) {
      //capital
      if('A'<=ch&&ch<='Z'&&'A'<=ch+n&&ch+n<='Z'){
           printf("%c",ch+n);
      }
      else if('A'<=ch&&ch<='Z'&&'Z'<ch+n){
           printf("%c",ch+n-'Z'+'A'-1);
      }
      //small   
       else if('a'<=ch&&ch<='z'&&'a'<=ch+n && ch+n <'z'){
           printf("%c",ch+n);
      }
       else if('a'<=ch&&ch<='z'&&'z'<ch+n){
           printf("%c",ch+n-'z'+'a'-1);
      }
      else {
           printf("%c",ch);
      }
  }

  printf("\n");

  fclose(sfp); /* コピー元ファイルのクローズ */

  return 0;
}