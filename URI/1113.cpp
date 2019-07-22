#include <stdio.h>
main ()
{
int X, Y;
while (1) {
scanf("%d %d", &X, &Y);
if (X==Y) {
    break;
}
if (X>Y) {
printf("Decrescente\n");
}
if (X<Y) {
printf("Crescente\n");
}
}
}