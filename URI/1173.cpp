#include <stdio.h>
main ()
{
    int X[10], i, z;
    scanf("%d", &z);
    for (i=0; i<10; i++) {
        if (i==0) {
      X[i]= z;
      } else {
      X[i] = X[i-1] * 2;
      }
      printf("N[%d] = %d\n", i, X[i]);
}
}