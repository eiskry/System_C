#include <stdio.h>
#include <string.h>

int main(void) {
    int v,s,n;
    int i,j,k,l,m;
    int sum;
    int gene;
    
    char board1[100][100], board2[100][100];
    int count[100][100], tmp[100][100],future[100][100];

    //read board size
    scanf("%d", &v);
    scanf("%d",&s);


    //first set board1 for  input format
    for (i=0;i<v;i++){
        for (j=0;j<2*s;j++){
            board1[i][j]= ('O');
        }
    }

    // //print board1
    // for (i = 0; i < v; i++) {
    //     for (j = 0; j < 2*s; j++) {
    //         printf("%c", board1[i][j]);
    //     }     printf("\n");
    // }
    
    //set board1 for input
    for (i = 0; i < v; i++) {
        for (j = 0; j < 2*s; j++) {
         scanf("%c", &board1[i][j]);
        }
    }

    // //print board1
    // printf("input");
    // printf("\n");
    // for (i = 0; i < v; i++) {
    //     for (j = 0; j < 2*s; j++) {
    //         printf("%c", board1[i][j]);
    //     }     printf("\n");
    // }

    //delete space to board2
    i=0;
    j=0;
    k=0;
    while (i < v) {
        k=0;
        for (j=0;j < 2*s;j++) {
            if (board1[i][j]!=(' ')) {
                board2[i][k]=board1[i][j];
                k++;
            }
        }
        i++;
        
    }

 
    // printf("\n");
    // printf("--------------------------");
    // printf("\n");

    // //print board2
    // printf("0th generation");
    // printf("\n");
    // for (i = 0; i < v; i++) {
    //     for (j = 0; j < k; j++) {
    //         printf("%c", board2[i][j]);
    //     }     printf("\n");
    // }
    // printf("\n");
    // printf("--------------------------");

    //scan N
    scanf("%d",&n);

    //////////////////////////////////////////////////////////

    //o -> 1, . -> 0
    for (i = 0; i < v; i++) {
        for (j = 0; j < k; j++) {
            if(board2[i][j]==('O')) {
                count[i][j]=1;
            }
            else if (board2[i][j]==('.')){
                count[i][j]=0;
            }
            else if(board2[i][j]==(' ')) {
                count[i][j]=(' ');
            }
        }
    } 


    //set tmp
    for (i = 0; i < v; i++) {
        for (j = 0; j < s; j++) {
                tmp[i][j]=count[i][j+1];
        }    
    }

//  printf("\n");

//      for (i = 0; i < v; i++) {
//         for (j = 0; j < s; j++) {
//             printf("%d", tmp[i][j]);
//         }     printf("\n");
//     }

    // for (i = 0; i < v; i++) {
    //     for (j = 0; j < s; j++) {
    //         future[i][j]=tmp[i][j];
    //     }    
    // }

    //////////////////////////////////////////////////////////


    // for(gene=0;gene<n;gene++) {
    

    //print 1th generaion
    printf("\n");
    printf("1th generation\n");
    printf("\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < s; j++) {
          if(tmp[i][j]==1){
              printf("%c",('O'));
          } else {
              printf("%c",('.'));
          }
        }     printf("\n");
    }
    printf("\n");
    printf("--------------------------");
    printf("\n");

     for (i = 0; i < v; i++) {
            for (j = 0; j < s; j++) {
                    future[i][j]=tmp[i][j];
            }    
        }

    for (gene=0;gene<n-1;gene++){

        //future -> tmp
        for (i = 0; i < v; i++) {
            for (j = 0; j < s; j++) {
                    tmp[i][j]=future[i][j];
            }    
        }

        for (int l = 0; l < v ; l++) 
            { 
                for (int m = 0; m < s ; m++) 
                { 
                    // finding no Of Neighbours that are alive 
                    int aliveNeighbours = 0; 
                    for (int i = -1; i <= 1; i++) 
                        for (int j = -1; j <= 1; j++) 
                            aliveNeighbours += tmp[l + i][m + j]; 
    
                    // The cell needs to be subtracted from 
                    // its neighbours as it was counted before 
                    aliveNeighbours -= tmp[l][m]; 
    
                    // Implementing the Rules of Life 
    
                    // Cell is lonely and dies 
                    if ((tmp[l][m] == 1) && (aliveNeighbours < 2)) 
                        future[l][m] = 0; 
    
                    // Cell dies due to over population 
                    else if ((tmp[l][m] == 1) && (aliveNeighbours > 3)) 
                        future[l][m] = 0; 
    
                    // A new cell is born 
                    else if ((tmp[l][m] == 0) && (aliveNeighbours == 3)) 
                        future[l][m] = 1; 
    
                    // Remains the same 
                    else
                        future[l][m] = tmp[l][m]; 
                } 
            } 

     printf("\n");

    //  for (i = 0; i < v; i++) {
    //     for (j = 0; j < s; j++) {
    //         printf("%d", future[i][j]);
    //     }     printf("\n");
    // }

    //print result
    printf("\n");
    printf("%dth generation\n",gene+2);
    printf("\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < s; j++) {
          if(future[i][j]==1){
              printf("%c",('O'));
          } else {
              printf("%c",('.'));
          }
        }     printf("\n");
    }
    printf("\n");
    printf("--------------------------");
    printf("\n");

    }



    


    return 0;
}