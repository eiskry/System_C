#include<stdio.h>
int main(void) {
    int x;
    printf("Plese input?");
    scanf("%d", &x);
    if (x<0) {
        printf("Input is negative\n");
        x = -x;
    }
    printf("Absolute number is %d\n", x);
    return 0;
}