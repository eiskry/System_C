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

struct timespec {
  time_t tv_sec; /* Seconds.  */
  long tv_nsec;  /* Nanoseconds.  */
};



int main(int argc, char *argv[])
{
    int M,N;
    int i,j;
    int sum1,sum2;
    FILE *fp;
    int data1[100000];
    struct data2 *data2;
    struct timespec ts;
    struct tm tm;

    M= atoi(argv[1]);
    N= atoi(argv[2]);
    
    //data1
    i=0;
    while (i!=M){
        data1[i]=1;
        i++;
    }
    // data1 until i-1 

    //add data1
    for (j=0;j<N;j++){
      sum1=0;
      for (i=0;i<M;i++){
        sum1+=data1[i];      
      }
    }

    //data2
    j=0;
   for (j=0; j != M;j+1) {
    addList();
    j++;
  }

  //add data2
  

    return 0;
}


