#include <stdio.h>

#define N 100

int main(void)
{
  double a[N][N], b[N][N], c[N][N];
  int i, j, k, n;

  scanf("%d", &n);
  // 行列A,B,cを初期化
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i][j] = 0.0;
      b[i][j] = 0.0;
      c[i][j] = 0.0;
    }
  }

  // 行列Aを入力の１つ目の行列とする
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%lf", &a[i][j]);
    }
  }

  scanf("%d", &n);

  // 行列Bを入力の２つ目の行列とする
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%lf", &b[i][j]);
    }
  }

  //　行列Aを表示
  printf("input a");
  printf("\n");
  for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        printf("%f ", a[i][j]);
      }     printf("\n");
    } 

  printf("\n");
  
  // 行列Bを表示
  printf("input b");
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%f ", b[i][j]);
    }      printf("\n");
  }

  printf("\n");

  //　行列AとBの積を計算し、その結果を行列Cとする
   for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      for (k=0;k<n;k++) {
      c[i][j]+=a[i][k]*b[k][j];
      }
    }
  }


   // 行列Cを表示
  printf("result");
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%f ", c[i][j]);
    }      printf("\n");
  }

  return 0;
}