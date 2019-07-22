#include <stdio.h>
main(){
int X, A;
scanf("%d", &X);
for (A=0; A<=X; A++) {
    if (A % 2 != 0) {
        printf("%d\n", A);
    }
}
}