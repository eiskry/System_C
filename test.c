#include <stdio.h>
int main(void)
{
	int i;
    double sum=0;
	for (int i=1;i<1000000;i++){
        sum=sum+(1.0/i);
	    printf("%d\n",i);
        printf("%f\n",sum);
        if (sum>12.0){
            break;
        }
    }
	
    printf("\n");
	printf("%f\n",sum);
	printf("%d\n",i);
	return 0;
}