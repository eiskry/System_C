#include<stdio.h>

の使用例: 集合
int main(void)
{
int a[10], i, flag;
for (i = 0; i < 10; i++) {
scanf("%d", &a[i]);
}
flag = 0;
for (i = 0; i < 10; i++) {
if (a[i] == 3) {
flag = 1;
break;
}
}
if (flag) {
printf("Number 3 was found.¥n");
} else {
printf("Number 3 was not found.¥n");
}
return 0;
}