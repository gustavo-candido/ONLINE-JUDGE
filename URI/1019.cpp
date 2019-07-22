#include <stdio.h>
main ()
{
int N;
scanf ("%d", &N);
int H,M,S;
H = N / 3600;
M = (N - (H * 3600)) / 60;
S = (N - (H * 3600 + M * 60))/1;
printf ("%d:%d:%d\n", H,M,S);

}