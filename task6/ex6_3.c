#include <stdio.h>
#include <string.h>

void replace_message(char *buf)
{
  char input[256];
  if (fgets(input, 256, stdin) == NULL) {
    return;
  }
  strcpy(buf, input);
}

int main(void)
{
  char buf1[10], buf2[10], buf3[10];
  int z = 0x12345678;

  strcpy(buf1, "Hello\n");
  strcpy(buf2, "safe\n");
  strcpy(buf3, "world\n");

  printf("%s", buf1);
  printf("%s", buf2);
  printf("%s", buf3);
  printf("Your ID=0x%08x\n", z);

  printf("Input? ");
  fflush(stdout);
  replace_message(buf2);

  printf("%s", buf1);
  printf("%s", buf2);
  printf("%s", buf3);
  printf("Your ID=0x%08x\n", z);

  return 0;
}