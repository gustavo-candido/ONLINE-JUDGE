#include <stdio.h>
main ()
{
int N, I=1;
scanf("%d", &N);
while (I<=N) {
 printf ("%d %d %d\n", I, (I * I), (I * I * I));
 printf ("%d %d %d\n", I, (I * I) + 1, (I * I * I) + 1);
 I++;
 }
}