//trib.c
#include <stdio.h>

typedef int boolean ;
boolean const false = 0 ;
boolean const true = !0 ;


boolean Integer_contains (int number, int digit)
 {
      if (number==0) return digit==0 ;
 else if (number<0) return Integer_contains (-number, digit) ;
 else
 {
while (0<number)
 {
/* 1の位の数が digit かどうか確認してるよぉ */
 if (number % 10 == digit) return true ;
 number /= 10 ;
 }
return false ;
 }
}


int main(void){
	int n =33333;
    int sum=0;
    for (int i=1;i<n+1;i++){
        if( ((i%3)==0 ) || ((Integer_contains(i, 3)) ) ) {
            sum=sum+i;
        
        }
    }
	printf("%d\n", sum);
}