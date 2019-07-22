#include<stdio.h>
#include<string.h>
#define max(x,y) (x>y ? x:y)
 int N,pac, qt[101], peso[101], box[101][51], tot, cont;

int knap (int id, int w) {
    if(id<0 || !w) return 0;
    if(box[id][w] != -1) return box[id][w];
    if(peso[id] > w) return box[id][w] = knap(id-1, w);

    return box[id][w] = max(knap(id-1, w), knap(id-1, w - peso[id])+qt[id]);
}
int main ()
{
    scanf("%d", &N);

    for(int NC=0; NC<N; NC++){
        scanf("%d", &pac);
        tot= cont = 0;
        memset(box, -1, sizeof(box));
        for(int c=1; c<=pac; c++) {
            scanf("%d %d", &qt[c], &peso[c]);
        }
        printf("%d brinquedos\n", knap(pac, 50));

        int i=pac, k=50;

        while(i && k) {
            if(box[i][k] != box[i-1][k]) {
                tot+=peso[i];
                cont++;
                k-=peso[i];
            }
            i--;
        }
        printf("Peso: %d kg\n", tot);
        printf("sobra(m) %d pacote(s)\n\n", pac-cont);

    }
}
