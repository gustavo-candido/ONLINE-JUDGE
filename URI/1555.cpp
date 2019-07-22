#include <stdio.h>
#include <math.h>

int Rafael (int x, int y) {
    int R = pow((3*x), 2) + pow (y, 2);
    return R;
}
int Beto (int x, int y) {
    int B = 2 * (pow (x, 2)) + pow ((5*y), 2);
    return B;
}
int Carlos (int x, int y) {
    int C = -100 * x + pow (y, 3);
    return C;
}

main ()
{
    int N, i, x, y, R, B, C;
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d %d", &x, &y);
        R = Rafael(x,y);
        B = Beto(x,y);
        C = Carlos(x,y);
        if (R>B && R>C) printf("Rafael ganhou\n");
        else if (B>R && B>C) printf("Beto ganhou\n");
        else if (C>R && C>R) printf("Carlos ganhou\n");
    }
}