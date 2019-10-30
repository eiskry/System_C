#include <stdio.h>

#define N 100

int main(void)
{
  double a[N][N], b[N][N], c[N][N];
  int i, j, k, n;

  scanf("%d", &n);
  // set A,B,c
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i][j] = 0.0;
      b[i][j] = 0.0;
      c[i][j] = 0.0;
    }
  }

  // set A
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%lf", &a[i][j]);
    }
  }

  scanf("%d", &n);

  // set B
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%lf", &b[i][j]);
    }
  }

  //print a
  printf("input a");
  printf("\n");
  for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        printf("%f ", a[i][j]);
      }     printf("\n");
    } 

  printf("\n");
  
  // print b
  printf("input b");
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%f ", b[i][j]);
    }      printf("\n");
  }

  printf("\n");

  //calculate
   for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      for (k=0;k<n;k++) {
      c[i][j]+=a[i][k]*b[k][j];
      }
    }
  }


   // print c
  printf("result");
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%f ", c[i][j]);
    }      printf("\n");
  }

  return 0;
}