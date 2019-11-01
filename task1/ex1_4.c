#include <stdio.h>
#include <string.h>

int main(void) {
    int v,s,n;
    int i,j,k,l,m;
    int sum;
    int gene;
    
    char board1[100][100], board2[100][100];
    int count[100][100], tmp[100][100],future[100][100];

    //　盤面の縦の長さを読み込む
    scanf("%d", &v);

    //　盤面の横の長さを読み込む
    scanf("%d",&s);


    //　すべてのセルが生きているとし、board1として初期化する
    for (i=0;i<v;i++){
        for (j=0;j<2*s;j++){
            board1[i][j]= ('O');
        }
    }
    
    //　セルの情報を入力に対応させる
    for (i = 0; i < v; i++) {
        for (j = 0; j < 2*s; j++) {
         scanf("%c", &board1[i][j]);
        }
    }

    //  空白を除いた入力をboard2とする
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

    //　Nを読み込む
    scanf("%d",&n);

    //////////////////////////////////////////////////////////

    //Oを1へ, .を0へと変換する
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

    //  現在のセルの情報としてtmpを定義する
    for (i = 0; i < v; i++) {
        for (j = 0; j < s; j++) {
                tmp[i][j]=count[i][j+1];
        }    
    }

    //　第一世代の盤面の情報を出力する
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

    //　G世代目までのシミュレーションの結果を出力する

    for (gene=0;gene<n-1;gene++){

        //次の世代の情報futureを現在の世代の情報tmpとして更新する
        for (i = 0; i < v; i++) {
            for (j = 0; j < s; j++) {
                    tmp[i][j]=future[i][j];
            }    
        }

        for (int l = 0; l < v ; l++) 
            { 
                for (int m = 0; m < s ; m++) 
                { 
                    // 生きている周りのセルを数える
                    int aliveNeighbours = 0; 
                    for (int i = -1; i <= 1; i++) 
                        for (int j = -1; j <= 1; j++) 
                            aliveNeighbours += tmp[l + i][m + j]; 
                    aliveNeighbours -= tmp[l][m]; 
    
                    //　ライフゲームのルールを適用する
    
                    // 過疎
                    if ((tmp[l][m] == 1) && (aliveNeighbours < 2)) 
                        future[l][m] = 0; 
    
                    // 過密 
                    else if ((tmp[l][m] == 1) && (aliveNeighbours > 3)) 
                        future[l][m] = 0; 
    
                    // 誕生
                    else if ((tmp[l][m] == 0) && (aliveNeighbours == 3)) 
                        future[l][m] = 1; 
    
                    // 生存
                    else
                        future[l][m] = tmp[l][m]; 
                } 
            } 

     printf("\n");

    //　結果を出力する
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