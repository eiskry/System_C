#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct data2 {
  int number;
  struct data2 *next;
};

struct data2 *head = NULL;

void addList()
{
    struct data2 *lp;
    lp = (struct data2 *)malloc(sizeof(struct data2));
    if (lp == NULL) {
    fprintf(stderr, "No more memory¥n");
    exit(1);
    }
    lp->next = head;
    lp->number = 1;
    head = lp;
}

int main(int argc, char *argv[])
{
    int M,N;
    int i,j;
    int sum1,sum2;
    int *data1;
    data1=(int *)malloc(sizeof(int)*10000000);
    struct data2 *data2;
    
    clock_t start,end;

    M= atoi(argv[1]);
    N= atoi(argv[2]);
    
    //make data1
    start=clock();
    i=0;
    while (i!=M){
        data1[i]=1;
        i++;
    }
    end=clock();
    printf("Make the Array: %.4fseconds\n",(double)(end-start)/CLOCKS_PER_SEC);
    // data1 until i-1 
  

    //calcu data1
    start=clock();
    for (j=0;j<N;j++){
      sum1=0;
      for (i=0;i<M;i++){
        sum1+=data1[i];      
      }
    }
    end=clock();
    printf("Calculate the Array: %.4fseconds\n",(double)(end-start)/CLOCKS_PER_SEC);

    //release data1
    start=clock();
    free(data1);
    end= clock();
    printf("Release the Array: %.4fseconds\n",(double)(end-start)/CLOCKS_PER_SEC);


    //make data2
    start=clock();
    j=0;
   for (j=0; j != M;j+1) {
    addList();
    j++;
  }
  end = clock();
    printf("Make the List: %.4fseconds\n",(double)(end-start)/CLOCKS_PER_SEC);

  //calcu data2
  start=clock();
  for(i=0;i<N;i++){
    sum2=0;
    for(data2=head;data2!=NULL;data2=data2->next){
      sum2+=data2->number;
    }
  }
  end = clock();
  printf("Calculate the Array: %.4fseconds\n",(double)(end-start)/CLOCKS_PER_SEC);

  //release data2
   start=clock();
    free(data2);
    end= clock();
    printf("Release the List: %.4fseconds\n",(double)(end-start)/CLOCKS_PER_SEC);



  printf("S of array is %d\n",sum1);
  printf("S of list is %d\n",sum2);


    return 0;
}


