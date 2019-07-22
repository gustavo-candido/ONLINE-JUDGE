#include <stdio.h>
main ()
{
    int i=0, I[5], P[5], X, p=0, im=0, imp=0, par=0, m=0, n=0;
    while(i<15) {
        scanf("%d", &X);
    if (X%2 == 0) {
        P[p] = X;
        p++;
    }
    if (p==5) {
            p = 0;
            for (m=0; m<5; m++)
            printf("par[%d] = %d\n", m,P[m]);
        }
    if (X%2 != 0) {
        I[im] = X;
        im++;
    }
    if (im==5) {
            im = 0;
            for (n=0; n<5; n++)
            printf("impar[%d] = %d\n", n,I[n]);
        }
        i++;
  }
  if (im!=0) {
    for (imp=0; imp<im; imp++) {
        printf("impar[%d] = %d\n", imp,I[imp]);
    }
  }
  if (p!=0) {
    for (par=0; par<p; par++) {
        printf("par[%d] = %d\n", par, P[par]);
    }
  }
}