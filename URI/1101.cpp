#include <stdio.h>
main ()
{
int M, N, A, B, i, k=0;
while (1) {
scanf("%d %d", &M, &N);
if (M>N) {
    A = M;
    B = N;
}
if (M<N) {
    A = N;
    B = M;
}
if (A==0 || B==0 || A==0 && B==0) {
    break;
}
for (i=B; i<=A; i++) {
    k = i + k;
    printf("%d ", i);
} printf("Sum=%d\n", k);
k = 0;
}
}