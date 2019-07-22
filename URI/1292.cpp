#include <stdio.h>
#define eita 1.0673956817111820792955340577925989117436218758753876317659378558255893790190790832470682986775224439013376


int main ()
{
    double X;
    while(scanf("%lf", &X) != EOF) {
        printf("%.10F\n", eita*X);
    }
}
