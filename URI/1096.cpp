#include <stdio.h>
main ()
{
int I=1, J= 7;
while (I<=9) {
    printf("I=%d J=%d\n", I, J);
    J--;
    printf("I=%d J=%d\n", I, J);
    J--;
    printf("I=%d J=%d\n", I, J);
    J+=2;
    I+=2;
}
}