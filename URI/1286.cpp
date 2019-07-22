#include <stdio.h>
#include <string.h>
#define max(x, y) (x>y ? x:y)

int N, P, qt[25], peso[35], box[25][35];

int knap (int id, int w) {
    if(id==N || !w) return 0;
    if(box[id][w] != -1) return box[id][w];
    if(peso[id] > w) return box[id][w] = knap(id+1, w);

    return box[id][w] = max(knap(id+1, w), knap(id+1, w - peso[id])+qt[id]);
}
int main ()
{
    while(scanf("%d", &N), N){
        scanf("%d", &P);
        for(int i=0; i<N; i++) {
            scanf("%d %d", &qt[i], &peso[i]);
        }
        memset(box, -1, sizeof(box));
        printf("%d min.\n", knap(0, P));
    }
}
