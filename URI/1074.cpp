#include <stdio.h>
main(){
    int N, a, X;
    scanf("%d", &N);
    for (a=0; a<N; a++){
        scanf("%d", &X);
        if (X==0) {
            printf("NULL\n");
        }
        if (X%2==0 && X>0) {
            printf("EVEN POSITIVE\n");
        }
        if (X%2==0 && X<0) {
            printf("EVEN NEGATIVE\n");
        }
        if (X%2!=0 && X>0) {
            printf("ODD POSITIVE\n");
        }
        if (X%2!=0 && X<0) {
            printf("ODD NEGATIVE\n");
        }

}
}