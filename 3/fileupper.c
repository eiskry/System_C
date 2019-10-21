#include <stdio.h>

int main(int argc, char *argv[])
{
  int ch,i;
  char s[100];
  FILE *sfp, *dfp;

  /* コマンドライン引数が2つ指定されているかどうか確認する */
  if (argc != 3) {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }

  if ((sfp = fopen(argv[1], "r")) == NULL) { /* コピー元ファイルのオープン */
    fprintf(stderr, "Can't open %s\n", argv[1]);
    return 1;
  }

  if ((dfp = fopen(argv[2], "w")) == NULL) { /* コピー先ファイルのオープン */
    fprintf(stderr, "Can't open %s\n", argv[2]);
    fclose(sfp); /* コピー元ファイルのクローズ */
    return 1;
  }

  while ((ch = fgetc(sfp)) != EOF) {
    fputc(ch, dfp); /* コピー先ファイルにコピー元ファイルの内容を書き込む */
  }

  fscanf(dfp,"%s",s);
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
        s[i] = s[i] - 'a' + 'A';
    }
  }

  fclose(dfp); /* コピー先ファイルのクローズ */
  fclose(sfp); /* コピー元ファイルのクローズ */

  return 0;
}