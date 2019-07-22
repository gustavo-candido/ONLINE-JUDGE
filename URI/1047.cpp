#include <stdio.h>
#include <stdlib.h>
main ()
{
int H[2], M[2], A=0, B=0;
scanf("%d %d %d %d", &H[0], &M[0], &H[1], &M[1]);
if (H[0]==H[1] && M[0] == M[1]) {
    A = 24;
    B = 0;
}
else if (H[0]==H[1] && M[0] != M[1] && M[1] > M[0]) {
        A = 0;
        B = M[1] - M[0];
}
else if (H[0]==H[1] && M[0] != M[1] && M[1] < M[0]) {
        A = 23;
        B = 60 - M[0] + M[1];
}
else if (H[0]!=H[1] && H[1] > H[0] && M[0] == M[1]) {
        A = H[1] - H[0];
        B = 0;
}
else if (H[0]!=H[1] && H[1] < H[0] && M[0] == M[1]) {
        A = abs(H[0]-24) + H[1];
        B = 0;
}
else if (H[0] != H[1] && M[0] != M[1] && H[0] < H[1] && M[0] < M[1]) {
        A = H[1] - H[0];
        B = M[1] - M[0];
}
else if (H[0] != H[1] && M[0] != M[1] && H[0] < H[1] && M[0] > M[1]) {
        A = H[1] - (H[0] + 1);
        B = 60 - M[0] + M[1];
}
else if (H[0] != H[1] && M[0] != M[1] && H[0] > H[1] && M[0] < M[1]) {
        A = abs(H[0]-24) + H[1];
        B = M[1] - M[0];
}
else if (H[0] != H[1] && M[0] != M[1] && H[0] > H[1] && M[0] > M[1] && H[1] == 0 ) {
        A = 24 - (H[0] + 1);
        B = 60 - M[0] + M[1];
}
else if (H[0] != H[1] && M[0] != M[1] && H[0] > H[1] && M[0] > M[1]) {
        A = H[1] - (H[0] + 1);
        B = 60 - M[0] + M[1];
}
printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", A, B);
}