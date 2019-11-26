#include<stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    int n;
    
    if (argc != 2) {
            printf("Usage: %s <number 1> <number 2>¥n", argv[0]);
            return 0;
    }
    n = atoi(argv[1]);

    for(int i=0;i<n;i++){
        printf("1\n");
    }

    return 0;
}