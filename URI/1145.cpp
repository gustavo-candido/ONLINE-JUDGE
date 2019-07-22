#include <stdio.h>
main ()
{
int X, Y, I=1;
scanf("%d %d", &X, &Y);
while (I<=Y) {
    if (I%X==0) {
        printf("%d\n", I);
    }
    else {
    printf("%d ", I);
    }
    I++;
}
 }