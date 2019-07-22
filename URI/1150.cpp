#include <stdio.h>
#include <stdlib.h>
#include <math.h>


 main(int argc, char *argv[]) {

   int X, Z, S, i, t=0;

   S=0;

   scanf("%d", &X);

   Z=X;

   if(X>0){
   for(i=0; X >= Z; i++){

      scanf("%d", &Z);

   }

   for(i=X; S < Z; i++){

      S=S+i;

      t++;
   }

   printf("%d\n", t);
}

   else if(X<0){
   for(i=0; X >= Z; i++){

      scanf("%d", &Z);

   }
   if(Z<0){
   Z=abs(Z);

   for(i=X; S < Z; i++){

      S=S+i;

      t++;
   }
   t=t-1;
}
   else if(Z>0){
      Z=abs(Z);

   for(i=X; S < Z; i++){

      S=S+i;

      t++;
   }

   }

   printf("%d\n", t);
}
}