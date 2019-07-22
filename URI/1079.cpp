#include <stdio.h>
main()
{
    int N, i;
    float a,b,c, media;
    scanf("%d", &N);
    for(i=0; i<N; i++) {
    scanf("%f %f %f", &a, &b, &c);
    media=(a*2+b*3+c*5)/(2+3+5);
    printf("%.1f\n", media);

    }
}