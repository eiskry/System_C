#include <stdio.h>

int plus(int x, int y)
{
    int z;
    z = x + y;
    return z;
}

int main(void)
{
    int a, b, c;
    a = 3;
    b = 6;
    printf("%d + %d = ", a, b);
    c = plus(a, b);
    printf("%d¥n", c);
    return 0;
}