#include <stdio.h>

int main ()
{
    char CPF[20];
    int b1, b2, aux, cont;

    while(gets(CPF)!= NULL) {
        b1 = b2 = 0;
        cont=1;
        for (int i=0; i<11; i++) {
            if (CPF[i] >= 48  && CPF[i] <= 57) {
                aux = (int)CPF[i] - 48;
                b1+=cont*aux;
                b2+=(10-cont)*aux;
                cont++;
            }
        }
        b1%=11;
        if (b1==10)b1=0;
        b2%=11;
        if (b2==10)b2=0;
        if ((int)CPF[12]-48== b1 && (int)CPF[13]-48 == b2) printf("CPF valido\n");
        else printf("CPF invalido\n");
    }
}