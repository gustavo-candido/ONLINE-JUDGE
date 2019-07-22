#include <stdio.h>
main ()
{
int N;
scanf ("%d", &N);
int A,M,D;
A = N / 365;
M = (N - (A * 365)) / 30;
D = (N - (A * 365 + M * 30))/1;
printf ("%d ano(s)\n", A);
printf ("%d mes(es)\n",M);
printf ("%d dia(s)\n",D);
}
