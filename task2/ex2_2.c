#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int ch, n, count;
  char str[255];
  FILE *fp;

  /* コマンドライン引数が2つ指定されているかどうか確認する */
  if (argc != 3) {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }

  n=atoi(argv[1]);
  printf("Read %d lines:\n", n);

  if ((fp = fopen(argv[2], "r")) == NULL) { /* ファイルのオープン */
    fprintf(stderr, "Can't open %s\n", argv[1]);
    return 1;
  }

  count=0;

 
    while ((fgets(str,255,fp)!=NULL)) {
        printf("%s",str);
        count++;
        if(count==n){
            break;
        }
    }

  fclose(fp); /* ファイルのクローズ */

  return 0;
}