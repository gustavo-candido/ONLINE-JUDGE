#include <stdio.h>

int main ()
{
    int N, Ax, Bx, Cx, Dx, Rx, Ay, By, Cy, Dy, Ry;

    scanf("%d", &N);

    for (int c=0; c<N; c++) {
        scanf("%d %d %d %d %d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy, &Rx, &Ry);
        if ((Rx >= Ax && Rx >= Dx) && (Rx <= Bx && Rx <= Cx)&&(Ry >= Ay && Ry >= By)&& (Ry <= Cy && Ry <= Dy))
            printf("1\n");
        else
            printf("0\n");
    }
}
