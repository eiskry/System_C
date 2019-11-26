#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int M,N;
    int i;
    FILE *fp;
    int data1[100000];

    M= atoi(argv[1]);
    M= atoi(argv[2]);
    
    i=0;
    while (i!=M){
        data1[i]=1;
        i++;
    }

    printf("%d\n",data1[0]);


    return 0;
}


