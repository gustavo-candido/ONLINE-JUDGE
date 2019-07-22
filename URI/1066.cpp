#include<stdio.h>

main ()
{
   int V,Rod,Pos = 0,Neg = 0,Imp = 0,Par = 0;

   for(Rod = 0;Rod < 5;Rod ++){
      scanf("%d",&V);
      if (V > 0){
         Pos++;
      }
      if(V < 0){
         Neg++;
      }
      if(V % 2 == 0){
         Par++;
      }
      if(V % 2 != 0){
         Imp++;
      }
   }
   printf("%d valor(es) par(es)\n",Par);
   printf("%d valor(es) impar(es)\n",Imp);
   printf("%d valor(es) positivo(s)\n",Pos);
   printf("%d valor(es) negativo(s)\n",Neg);
}
