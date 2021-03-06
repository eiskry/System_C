#include <stdio.h>
//count lines in the file
int main(int argc, char *argv[])
{
    int ch, count;
    FILE *fp;

    if (argc != 2) {
        puts("missing file argument");
        return 1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("can't open %s\n", argv[1]);
        return 1;
    }

    count = 0;
    while ((ch = fgetc(fp)) != EOF)
        count++;

    printf("%d characters\n", count);
    fclose(fp);

    return 0;
}


