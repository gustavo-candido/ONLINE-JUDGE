#include <stdio.h>
main ()
{
int I=1, J= 60;
for (J = 60; J>=0; J-=5, I+=3) {
    I+3;
    J-5;
    printf("I=%d J=%d\n", I, J);
}
}
