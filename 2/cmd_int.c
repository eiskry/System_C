#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
int a, b;
if (argc != 3) {
fprintf(stderr, "Error: specify two integers.¥n");
exit(1); /* Terminate this program */
}
a = atoi(argv[1]); /* Convert string to integer */
b = atoi(argv[2]); /* Convert string to integer */
printf("%d + %d = %d¥n", a, b, a + b);
return 0;
}