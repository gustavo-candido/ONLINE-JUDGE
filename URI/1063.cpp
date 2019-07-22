#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

struct pilha {
    int tam;
    char letra[MAX];
};
typedef struct pilha pilha;

pilha *pilha_cria();
void pilha_destroi(pilha *A);
void push (pilha *A, int aux);
pilha  *pop (pilha *A);

main ()
{
    int N, c, cont;
    char *trem, *saida;
    pilha *estacao;
    while(scanf("%d", &N)) {
        if (N==0) break;
        trem = (char*) malloc(sizeof(char)*N);
        saida = (char*) malloc(sizeof(char)*N);
        estacao = pilha_cria ();
        cont = 0;
        for (c=0; c<N; c++) {
            scanf(" %c", &trem[c]);
        }
        trem[c] = '\0';
        for (c=0; c<N; c++) {
            scanf(" %c", &saida[c]);
        }
        saida[c] = '\0';
        for (c=0; c<N; c++) {
            push(estacao, trem[c]);
            while(estacao->tam>=0 && estacao->letra[estacao->tam-1] == saida[cont] && cont<N) {
                pop(estacao);
                cont++;
            }
        }
        if (estacao->tam==0 && cont==N && trem[cont-1] == trem[N-1]) {
                printf("\n");
            }
        else  {
            printf(" Impossible\n");
            //printf("Vagoes na estacao %d\ncont %d\ntrem[cont] = '%c' e trem[N-1] = '%c'\n", estacao->tam, cont, trem[cont], trem[N-1]);
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
    A->letra[A->tam] = aux;
    A->tam++;
    printf("I");
}
pilha  *pop (pilha *A) {
    A->letra[A->tam-1] = NULL;
    A->tam--;
    printf("R");
    return A;
}
