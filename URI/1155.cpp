#include <stdio.h>

int main() {

   double count, aux = 0.00, S = 0;

   for(count=1; count<=100; count++){
      aux = 1.0/count;
      S = S + aux;
   }

   printf("%.2f\n", S);


}