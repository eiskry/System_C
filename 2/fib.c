#include<stdio.h>

int main(void)
{
int a[11];
int i;
a[0] = 1;
a[1] = 1;
for (i = 2; i <= 10; i++) {
a[i] = a[i - 2] + a[i - 1];
}
printf("a[10] is %d.¥n", a[10]);
return 0;
}