#include <stdio.h>
#include <stdlib.h>

int compara (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

main ()
{
    int N, c=0, A[100000];
    scanf("%d", &N);
