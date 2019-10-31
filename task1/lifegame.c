#include <stdio.h>
#include <string.h>

int main(void) {
    int v,s,n;
    int i,j,k,l;
    
    char board1[100][100], board2[100][100];

    //read board size
    scanf("%d", &v);
    scanf("%d",&s);


    //first set board
    for (i=0;i<v;i++){
        for (j=0;j<2*s;j++){
            board1[i][j]= ('O');
        }
    }

    //print board
    for (i = 0; i < v; i++) {
        for (j = 0; j < 2*s; j++) {
            printf("%c", board1[i][j]);
        }     printf("\n");
    }
   
    

    //set board
    for (i = 0; i < v; i++) {
        for (j = 0; j < 2*s; j++) {
         scanf("%c", &board1[i][j]);
        }
    }

    //print board
    for (i = 0; i < v; i++) {
        for (j = 0; j < 2*s; j++) {
            printf("%c", board1[i][j]);
        }     printf("\n");
    }

    //delete space
    i=0;
    j=0;
    k=0;
    while (i < v) {
        for (j=0;j < 2*s;j++) {
            if (board1[i][j]!=(' ')) {
                board2[i][k]=board1[i][j];
                k++;
            }
        }
        i++;
    }

    printf("%d",i);
    printf("%d",k);
    

    //print board
    for (i = 0; i < v; i++) {
        for (j = 0; j < k; j++) {
            printf("%c", board2[i][j]);
        }     printf("\n");
    }

    //scan N
    scanf("%d",&n);
    



    printf("\n");


    return 0;
}