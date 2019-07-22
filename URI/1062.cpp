#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
struct pilha {
    int num[MAX], tam;
};
typedef struct pilha pilha;

pilha *pilha_cria();
void pilha_destroi(pilha *A);
void push (pilha *A, int aux);
pilha  *pop (pilha *A);

main ()
{
    pilha *estacao;
    int N, c, i, cont, *saida, trem;

    comeco:
    while (scanf("%d", &N)) {
        if (N==0) break;
        for (c=0; c>-1; c++) {
            saida = (int*)malloc(N*sizeof(int));
            estacao = pilha_cria();
            cont = 0;
            for (i=0; i<N; i++) {
				scanf("%d", &saida[i]);
                if (saida[i]==0) {printf("\n");goto comeco;}
                trem = i+1;
                push(estacao, trem);
                while(estacao->tam>=0 && estacao->num[estacao->tam-1] == saida[cont] && estacao->num[estacao->tam-1]<=N) {
                      pop(estacao);
                      cont++;
                }
            }
            if (trem==N && estacao->tam==0 && saida[cont-1]==saida[N-1]) {
                printf("Yes\n");
            }
            else {printf("No\n");
            //printf("trem = %d\nestacao->tam = %d\ncont = %d\n", trem, estacao->tam, saida[cont]==saida[N-1]);
            }
            free(saida);
            pilha_destroi(estacao);
        }
    }
}
pilha *pilha_cria (){
    pilha *A;
    A = (pilha*)malloc(sizeof(pilha));
    A->tam=0;
    return A;
}
void pilha_destroi(pilha *A){
    free(A);
}
void push(pilha *A, int aux) {
    A->num[A->tam] = aux;
    A->tam++;
}
pilha  *pop (pilha *A) {
    A->num[A->tam-1] = 0;
    A->tam--;
    
    return A;
}
