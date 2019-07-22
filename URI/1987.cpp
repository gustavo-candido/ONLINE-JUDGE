#include <stdio.h>

int main()
{
    int tam, sum;
    char num;

    while(scanf("%d", &tam) != EOF) {
      getchar();
        sum=0;
        for(int i=0; i<tam; i++) {
            scanf("%c", &num);
            sum+=num-'0';
        }printf("%d ", sum);
        if(sum%3==0)printf("sim\n");
        else printf("nao\n");
    }
}
