#include<stdio.h>
main()
{
   int a, n, sum=0, i;

   scanf("%d %d", &a, &n);
   while (n<1) {
    scanf ("%d", &n);
   }
      for(i = a; i<a+n; i++)
      {
         sum = sum + i;
      }
      printf("%d\n", sum);
}