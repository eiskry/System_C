#include <stdio.h>

void calc_sum_max_min(int *sump, int *maxp, int *minp, 
 int *items, int nitems)
{
    //sum
    *sump=0;
    for(int i=0;i<nitems;i++){
        *sump = *(items+i) +*sump;
   }
    
    *maxp = *items;
    *minp = *(items+1);

    //max
    for(int i=0;i<nitems;i++){
         if (*maxp<*(items+i)){
            *maxp = *(items+i);
        }
    }

    //min
    for(int i=0;i<nitems;i++){
         if (*(items+i)<*minp){
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