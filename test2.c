#include <stdio.h>
#include <math.h>

int check(int a, int b, int c){
    if(a*a+b*b==c*c){
        return 1;
    }
    else return 0;
}
 
int main() {
  int a, b, c;
  int count=0;
  int n=20;
  int record[5000];
  int value;
 
  for (a=1;a<n;a++){
      for (b=1;b<n;b++){
        for (c=1;c<n;c++){
            if ((a + b > c && a + c > b && b + c > a) && (a > 0 && b > 0 && c > 0)) {
                if(check(a,b,c)==1){
                    count=count+1;
                    value=a+b+c;
                    for (int i=0;i<count-1;i++){
                        if(record[i]==value){
                            count=count-1;
                            continue;
                        }
                        else {
                            record[count]=value;
                            printf("%s%d%s%d%s%d%s%d%s\n","No.",count-1,";  (a, b, c) = (",a,", ",b,", ",c,")" );
                            continue;
                        }
                    }
                }
            }
        }
    }
  }
  printf("%d\n",count);
  return 0;
}
