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
    FILE *fp;
    int data1[100000];
    struct data2 *data2;

    M= atoi(argv[1]);
    N= atoi(argv[2]);
    
    //data1
    i=0;
    while (i!=M){
        data1[i]=1;
        i++;
    }
    // data1 until i-1 

    //data2
    j=0;
   for (j=0; j != M;j+1) {
    addList();
    j++;
  }

    return 0;
}


