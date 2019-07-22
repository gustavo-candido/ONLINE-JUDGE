#include <stdio.h>
main ()
{
    int N;
    scanf("%d", &N);
    int I = N, fat = 1;
    while (I>0) {
    fat =  fat * I;
    I--;
}
printf("%d\n", fat);
}