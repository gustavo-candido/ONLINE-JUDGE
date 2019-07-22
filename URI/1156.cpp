#include <stdio.h>

int main() {

   double count=2, aux = 0.00, S = 1, gg=3;

   while (gg<=39){
      aux = gg/count;
      S = S + aux;
      gg+=2;
      count= count*2;
   }

   printf("%.2f\n", S);
}