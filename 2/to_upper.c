#include<stdio.h>

int main(void)
{
int i;
char s[10];
printf("Please input string? ");
scanf("%s", s);
for (i = 0; s[i] != '\0'; i++) {
if (s[i] >= 'a' && s[i] <= 'z') {
s[i] = s[i] - 'a' + 'A';
}
}
printf("Result = %s¥n", s);
return 0;
}