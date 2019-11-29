#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y)
{
        if (y == 0) {
                return x;
        } else {
                return gcd(y, x % y);
        }
}

int main(int argc, char *argv[])
{
    int m,n,r,tmp;

    if (argc != 3) {
            printf("Invalid input.\n");
            return 0;
    }
  
    m = atoi(argv[1]);
    if (m == 0){
     printf("Invalid input.\n");
            return 0;
    }
    n = atoi(argv[2]);
    if (n == 0){
     printf("Invalid input.\n");
            return 0;
    }
    if(m<n){
        tmp=m;
        m=n;
        n=tmp;
    }

    printf("%d\n", gcd(m, n));
}
