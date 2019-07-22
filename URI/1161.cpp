#include <stdio.h>
main()
{
    long long int  M, N;
    while( scanf("%lld %lld", &M,&N) != EOF) {
    long long int I = N, fat = 1;
    while (I>0) {
    fat =  fat * I;
    I--;
    }
    long long int J = M, FAT = 1;
    while (J>0) {
    FAT = FAT * J;
    J--;
    }
    printf("%lld\n", fat+FAT);
    }
}