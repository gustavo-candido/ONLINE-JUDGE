#include <stdio.h>
main(){
int X, A;
scanf("%d", &X);
int B = X + 12;
for (A=0; A<=B; A++) {
    if (A>=X && A<=B && A % 2 != 0) {
        printf("%d\n", A);
    }
}
}