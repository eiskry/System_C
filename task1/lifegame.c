#include <stdio.h>
#include <string.h>

int main(void) {
    int v,s,n;
    int i,j,k,l,m;
    int sum;
    
    char board1[100][100], board2[100][100],tmp[100][100];

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



    //print board
    for (i = 0; i < v; i++) {
        for (j = 0; j < k; j++) {
            printf("%c", board2[i][j]);
        }     printf("\n");
    }

    //scan N
    scanf("%d",&n);

    //count alive cells
    for (i = 0; i < v; i++) {
        for (j = 0; j < k; j++) {
            sum=0;
            if((i != 0)&&(j != 0)&&(i != v)&&(j != s)) {
                for(l=-1;l<2;l++){
                    for(m=-1;m<2;j++){
                        if((l!=0) || (m!=0)) {
                            sum ++;
                        }
                    }
                }
                tmp[i][j]=sum;
            }
        }
    }


    // sum=0;
    // for(i = 0; i < v; i++) {
    //     for(j = 0; j < s; j++) {
    //         tmp[i][j] = board2[i][j];
    //         //端っこのセルを除いての処理をする
    //         if((i != 0)&&(j != 0)&&(i != v)&&(j != s)) {
    //             for(k = -1; k < 2; k++) {
    //                 for(l = -1; l < 2; l++) {
    //                     if((k!=0) || (l!=0)) {
    //                         sum += board2[i+k][j+l];
    //                     } 
    //                 }
    //             } 
    //             if(board2[i][j]) {
    //             //セルの周りに2つか3つのセルがいたら生存
    //                 if((sum != 2) && (sum != 3)) {
    //                     tmp[i][j] = 0;
    //                 }
    //             }
    //             //セルの周りに3つのセルがいたら誕生
    //             else {
    //                 if(sum == 3) {
    //                     tmp[i][j] = 1;
    //                 }
    //             }
    //         }
    //         //それ以外は死滅
    //         else {
    //             tmp[i][j] = 0;
    //         }
    //     sum = 0;
    //     }
    // }
    // for(i = 0;i < 20;i++){
    //     for(j = 0;j < 20;j++){
    //     board2[i][j] = tmp[i][j];
    //     }
    // }

    

     //print board
    for (i = 0; i < v; i++) {
        for (j = 0; j < k; j++) {
            printf("%c", tmp[i][j]);
        }     printf("\n");
    }




    printf("\n");


    return 0;
}

// void update(){
//     int i, j, k, l;
//     int sum = 0;
//     int temp[v][s];
    
//     for(i = 0; i < v; i++) {
//         for(j = 0; j < s; j++) {
//             temp[i][j] = board2[i][j];
// //端っこのセルを除いての処理をする
//             if((i != 0)&&(j != 0)&&(i != 19)&&(j != 19)) {
//                 for(k = -1; k < 2; k++) {
//                     for(l = -1; l < 2; l++) {
//                         if((k!=0) || (l!=0)) {
//                             sum += board2[i+k][j+l];
//                         } 
//                     }
//                 } 
//                 if(board2[i][j]) {
//                 //セルの周りに2つか3つのセルがいたら生存
//                     if((sum != 2) && (sum != 3)) {
//                         temp[i][j] = 0;
//                     }
//                 }
//                 //セルの周りに3つのセルがいたら誕生
//                 else {
//                     if(sum == 3) {
//                         temp[i][j] = 1;
//                     }
//                 }
//             }
//             //それ以外は死滅
//             else {
//                 temp[i][j] = 0;
//             }
//         sum = 0;
//         }
//     }
//     for(i = 0;i < 20;i++){
//         for(j = 0;j < 20;j++){
//         board2[i][j] = temp[i][j];
//         }
//     }
// }    

