#include <stdio.h>
extern unsigned long gettsc32(void);
intfib(int n)
{
if (n < 2) return 1;
else return fib(n -2) + fib(n -1);
}
int main(void)
{
unsigned int n = 30, answer;
unsigned long t_beg, t_end;
t_beg= gettsc32();
answer = fib(n);
t_end= gettsc32();
printf("Fib(%d)=%d¥n", n, answer);
printf("TSC(lo32): %lu->%lu(+%ld)¥n",
t_beg, t_end,t_end-t_beg);
return 0;
}