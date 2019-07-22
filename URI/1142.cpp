#include <stdio.h>
main ()
{
int N, I=1, B=0;
scanf("%d", &N);
while (B<N) {
    if (I%4 != 0) {
        printf("%d ",I);
    }
    if (I%4 == 0) {
        printf("PUM\n");
        B++;
    }
    I++;
}
}


