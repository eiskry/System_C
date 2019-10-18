#include <stdio.h>

int main(void) {
    int x;
    x = 0;
    while (x < 100) {
        printf("x=%d\n", x);
        x = x + 1;
    }
    return 0;
}