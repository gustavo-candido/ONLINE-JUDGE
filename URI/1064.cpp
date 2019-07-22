#include<stdio.h>

main ()
{
   int s, b=0;
   float a=0, X, media;
   for (s = 0; s<=5; s++) {
    scanf("%f", &X);
    if (X>0) {
    b++;
    a = a + X;
   }
}
   media = a / b;
   printf("%d valores positivos\n", b);
   printf("%.1f\n", media);
}
