#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int seed,i,t;
int min,max;
int count1,count2;

if (argc != 2) {
    fprintf(stderr, "Input error!\n");
 return 1;
  }

seed = atoi(argv[1]);
srand(seed);

t=100000;
count1=0;
count2=0;

for(int i =0; i<t;i++){
  if(rand()%(t+1)>t/2){
    count1++;
  } else {
    count2++;
  }
}
printf("%d %d\n",count1,count2);


}
