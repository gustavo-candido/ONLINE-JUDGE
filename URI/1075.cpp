#include <stdio.h>
main(){
    int N, a;
    scanf("%d", &N);
    for (a=1; a<=10000; a++) {
        if (a%N==2) {
            printf("%d\n", a);
        }
    }
}
