#include <stdio.h>

void calc_sum_max_min(int *sump, int *maxp, int *minp, 
 int *items, int nitems)
{
   for(int i=0;i<nitems;i++){
        *sump=0;
        *sump = *(items+i) +*sump;
   }

    for(int i=0;i<nitems;i++){

         if (*(items+i)<*(items+i+1)){
            *maxp = *(items+i);
            *minp = t;
        } else {
            *maxp = t;
            *minp = *(items+i);
        }
    }
}



int main(void)
{
  int a[10] = { 80, 36, -55, 17, 22, -71, 60, 97, 34, -14 };
  int n = 10;
  int sum, max, min;
  calc_sum_max_min(&sum, &max, &min, a, n);
  printf("sum = %d\n", sum);
  printf("max = %d\n", max);
  printf("min = %d\n", min);
  return 0;
}