#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int num;
    int tam;
    struct Lista *prox;
} lista;
lista *cria ();
void insere (lista *inicio, int valor);
void remover (lista *inicio, int salt);

main ()
{
    int N, s, c, i, j;
    lista *circulo;
    scanf("%d", &N);
    for (i=0; i<N; i++){
            circulo =  cria();
            scanf("%d %d", &c, &s);
            insere (circulo, c);
            remover(circulo, s);
            circulo = circulo->prox;
            printf("Case %d: %d\n", i+1, circulo->num);
    }
}

lista *cria () {
    lista *circulo = (lista*)malloc (sizeof(lista));
    circulo->tam = 0;
    circulo->prox = NULL;
    return circulo;
}
void insere(lista *inicio, int valor) {
    int i;
    lista *tmp = inicio;
    for (i=valor; i>0; i--) {
        lista *novo = (lista*)malloc(sizeof(lista));
        novo->prox = inicio->prox;
        novo->num = i;
        inicio->prox = novo;
        inicio->tam++;
    }
    while (tmp->prox != NULL) {
        tmp = tmp->prox;
    }
    tmp->prox = inicio->prox;
}
void remover (lista *inicio, int salt) {
    lista *tmp;
    lista *ant;
    int i;
    while (inicio->tam != 1) {
        tmp = inicio->prox;
        ant = inicio;
        for (i=1; i<salt; i++) {
            ant  = tmp;
            tmp = tmp->prox;
        }
        ant->prox = tmp->prox;
        tmp = NULL;
        inicio->tam--;
        inicio->prox = ant->prox;
    }
}