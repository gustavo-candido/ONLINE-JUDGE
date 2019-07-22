#include <stdio.h>
main ()
{
float X, Y , Z, A, B, C;
scanf("%f %f %f", &X, &Y, &Z);

if (X>=Y && X>=Z) {
    A = X;
} if (Y>=X && Y>=Z) {
    A = Y;
} if (Z>=X && Z>=Y) {
    A = Z;
} if (X<=Y && X>=Z || X<=Z && X>=Y) {
    B = X;
} if (Y<=X && Y>=Z || Y<=Z && Y>=X) {
    B = Y;
} if (Z<=X && Z>=Y || Z<=Y && Z>=X) {
    B = Z;
} if (X<=Y && X<=Z) {
    C = X;
} if (Y<=X && Y<=Z) {
    C = Y;
} if (Z<=X && Z<=Y) {
    C = Z;
}
  while (1) {
    if (A >= B+C) {
      printf("NAO FORMA TRIANGULO\n");
      break;
    }  if ((A * A) == (B * B) + (C * C)) {
      printf("TRIANGULO RETANGULO\n");
    }  if ((A * A) > (B * B) + (C * C)) {
      printf("TRIANGULO OBTUSANGULO\n");
    }  if ((A * A) < (B * B) + (C * C)) {
      printf("TRIANGULO ACUTANGULO\n");
    }  if (A == B && B==C) {
      printf("TRIANGULO EQUILATERO\n");
    }  if (A==B && A!=C || A==C && A!=B || B==A && B!=C || B==C && B!=A || C==A && C!=B || C==A && C!=B ) {
      printf("TRIANGULO ISOSCELES\n");
    }
    break;
   }
}
