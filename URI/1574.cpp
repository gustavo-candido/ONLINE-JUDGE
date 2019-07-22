#include <stdio.h>

main ()
{
    int T, C, N, c, x, num;
    char A[100][50], aux[50], aux2[101];

    scanf("%d", &T);

    for (C=0; C<T; C++) {
        scanf("%d", &N);
        getchar();
        for (c=1; c<=N; c++) {
            scanf("%s", A[c]);
            if (A[c][0] == 'S') {
                scanf("%s", aux);
                scanf("%d", &num);
            }
            if (A[c][0] == 'L') aux2[c] = '<';
            else if (A[c][0] == 'R') aux2[c] = '>';
            else if (A[c][0] == 'S') {
            aux2[c] = aux2[num];
            }
        }
        for (c=1, x=0; c<=N; c++) {
            if (aux2[c] == '>') x++;
            if (aux2[c] == '<') x--;
        }
        printf("%d\n", x);
    }
}