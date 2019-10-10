#include <stdio.h>

int main(void){
    int x;
    printf("Plese input?");
    scanf("%d",&x);
    if (x>0) {
        printf("Input is positive\n");
    } else {
        printf("Input is negative or zero\n");
    }
    return 0;
}