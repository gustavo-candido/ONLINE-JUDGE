#include <stdio.h>
main ()
{
  int A, B=2002;
  while (1) {
    scanf ("%d", &A);
    if (A==B) {
        printf("Acesso Permitido\n");
        break;
    }
    else if (A!=B) {
        printf("Senha Invalida\n");
    }
  }
}

