#include <stdio.h>

int main(int argc, char *argv[])
{
  int ch,st, count,N;
  FILE *fp;

  scanf("%d", &N);

  /* コマンドライン引数が2つ指定されているかどうか確認する */
  if (argc != 3) {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }

  if ((fp = fopen(argv[1], "r")) == NULL) { /* ファイルのオープン */
    fprintf(stderr, "Can't open %s\n", argv[1]);
    return 1;
  }


  count = 0;
  while (((ch = fgetc(fp)) != EOF)&&(count !=N)) { /* 1文字ずつ読み込む */
      if (ch =='\n') {
          count++;
          fputc(ch,stdout);
          if (count == N) {
              break;
          }
      }
  }

  fclose(fp); /* ファイルのクローズ */

  return 0;
}