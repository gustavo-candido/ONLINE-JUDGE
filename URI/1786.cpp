#include <stdio.h>

int main ()
{
    char CPF[20];
    int b1, b2, aux;

    while(gets(CPF) != NULL) {
            b1=b2=0;
        for (int i=0; i<9; i++) {
            aux = (int)CPF[i]-48;
            b1+=aux*(i+1);
            b2+=aux*(9-i);
        }
        b1%=11;
        if (b1==10)b1=0;
        b2%=11;
        if (b2==10)b2=0;
        for(int i=0; i<9; i++) {
            if(i==3 || i==6)printf(".");
            printf("%c", CPF[i]);
        }
        printf("-%d%d\n", b1, b2);
    }
}