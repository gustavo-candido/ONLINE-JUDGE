#include <stdio.h>

main ()
{
    int N, c, i, nota[5], p, b, R;

    while (scanf("%d", &N) != EOF) {
            if (N==0) {
                break;
            }
            else {
                    for (c=0; c<N; c++) {
                            p=0;
                            b=0;
                        for (i=0; i<5; i++) {
                            scanf("%d", &nota[i]);
                            if (nota[i]>=0 && nota[i]<=127) {
                                    p++;
                                    R=i;
                            }
                            if (nota[c]>127) {
                                    b++;
                            }
                        }
                        if (p==1 && R==0) {
                                printf("A\n");
                        }
                        else if (p==1 && R==1) {
                                printf("B\n");
                        }
                        else if (p==1 && R==2) {
                                printf("C\n");
                        }
                        else if (p==1 && R==3) {
                                printf("D\n");
                        }
                        else if (p==1 && R==4) {
                                printf("E\n");
                        }
                        else {
                                printf("*\n");
                        }
                    }
            }
    }
}