#include <stdio.h>
main ()
{
int X, I=1;
while (1) {
scanf("%d", &X);
if (X==0) {
    break;
}
else {
    while (I<=X) {
        if (I<X) {
        printf("%d ", I);
        }
        if (I==X) {
        printf("%d\n", I);
        I=1;
        break;
        }
        I++;
    }
}
}
}