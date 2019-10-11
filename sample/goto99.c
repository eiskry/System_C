#include <stdio.h>
int main(void) {
    int x;
    x=0;
    again:
    if (x>=100) {
        goto stop;
    }
    printf("x=%d\n",x);
    x=x+1;
    goto again;
    stop:
    return 0;
}