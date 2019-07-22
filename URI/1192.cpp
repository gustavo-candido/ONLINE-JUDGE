#include <stdio.h>
#include <stdlib.h>

main ()
{
  char A[10], B[10], C;
  int X, Y, Z, i=0, j=2, z=0, x;
  scanf("%d\n", &x);
  for (z=0; z<x; z++) {
  fgets (A, 10, stdin);
  for (i=0, j=2; i<3, j>=0; i++, j--) {
    B[j] = A[i];
  }
  X = atoi(A);
  Y = atoi(B);
  C = A[1];
  if (X == Y) {
    Z = X * Y;
  }
  else if (X!=Y && C>=65 && C<=90) {
    Z = Y - X;
  }
  else if (X!=Y && C>=97 && C<=122) {
    Z = X + Y;
  }
  printf ("%d\n", Z);
  }
  i=0;
  j=2;
}