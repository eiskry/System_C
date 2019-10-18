#include <stdio.h>

#define N 100

int main(void)
{
  double a[N][N], b[N][N], c[N][N];
  int i, j, n;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i][j] = 0.0;
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%lf", &a[i][j]);
    }
  }

  scanf("%d", &n);

   for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      b[i][j] = 0.0;
      c[i][j] = 0.0;
    }
  }

   for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%lf", &b[i][j]);
    }
  }

for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      c[i][j] = a[i][j] * b[i][j];
    }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%f ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}
}