#include <stdio.h>

main ()
{
    int H, maior, H2;

    while (scanf("%d", &H) != EOF) {
        if (H==0) break;
        maior = 1;
        H2 = H;
        while (H2!=1) {
            if (maior<H2)maior=H2;
            if (H%2==0) H2 = (1.0/2.0) * H;
            else H2 = 3 * H + 1;
            H = H2;
        }
        printf("%d\n", maior);
    }
}
