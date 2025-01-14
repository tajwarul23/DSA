#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int oR=0,anD=0,xoR=0;
  for(int i=1; i<=n; i++){
    for(int j=1+1; j<=n; j++){
        if(i == j)continue;
        int a = (i | j), b = (i & j), c = (i ^ j);
        if((a > oR) && (a < k))oR = a;
        if((b > anD) && (b < k))anD = b;
        if((c > xoR) && (c < k))xoR = c;
        // printf("%d\n",c);
    }
  }
  printf("%d\n%d\n%d\n", anD, oR, xoR);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
