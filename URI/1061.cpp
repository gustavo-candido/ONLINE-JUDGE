#include <stdio.h>

main ()
{
  char A[10], B[10], W[5], X[5], Y[5], Z[5];
  int D1, D2, H1, H2, M1, M2, S1, S2, HT=0, MT=0, ST=0, DT=0, SX, SY;
  scanf ("%s %d %d %s %d %s %d %s %d %d %s %d %s %d", &A, &D1, &H1, &W, &M1, &X, &S1, &B, &D2, &H2, &Y, &M2, &Z, &S2);
  SX = S1 + (M1*60) + (H1 * 3600) + (D1 * 86400);
  SY = S2 + (M2*60) + (H2 * 3600) + (D2 * 86400);
  while (1) {
    if (SX == SY) {
        printf ("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", DT,HT, MT, ST);
        break;
    }
    else if (SX != SY) {
        S1++;
        ST++;
        SX++;
    }
    if (S1 == 60) {
        S1 = 0;
        M1++;
    }
    if (ST == 60) {
        ST = 0;
        MT++;
    }
    if (M1 == 60) {
        M1 = 0;
        H1++;
    }
    if (MT == 60) {
        MT = 0;
        HT++;
    }
    if (H1 == 24) {
        H1 = 0;
        D1++;
    }
    if (HT == 24) {
        HT = 0;
        DT++;
    }
  }
}