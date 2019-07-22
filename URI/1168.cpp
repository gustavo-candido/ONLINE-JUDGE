#include <stdio.h>
#include <string.h>

main ()
{
    int N,c=0, led, i;
    char A[150];

    scanf("%d ", &N);

    while (c<N) {
        scanf("%s", &A);
        led=0;

        for (i=0; i<strlen(A); i++) {
            if (A[i] == '1') {
                led = led + 2;
            }
            if (A[i] == '2' || A[i] == '3' || A[i] == '5') {
                led = led + 5;
            }
            if (A[i] == '4') {
                led = led + 4;
            }
            if (A[i] == '6' || A[i] == '9' || A[i] == '0') {
                led = led + 6;
            }
            if (A[i] == '7') {
                led = led + 3;
            }
            if (A[i] == '8') {
                led = led + 7;
            }
        }
        printf("%d leds\n", led);
        c++;
    }
}