#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    char nome[50];
    int salt;
    int tam;
    struct lista *prox;
    struct lista *ant;
}no;
no *cria ();
void insere (no *inicio, int teste);
void pop (no *inicio);

main ()
{
    int N;
    while (scanf("%d", &N)) {
        if (N==0) break;
        getchar();
        no *teste;
        teste = cria();
        insere(teste, N);
        pop(teste);
        teste = teste->prox;
        teste = teste->ant;
        printf("Vencedor(a): %s\n", teste->nome);
    }
}

no *cria () {
    no *inicio = (no*)malloc(sizeof(no));
    inicio->tam=0;
    inicio->prox=NULL;
    inicio->ant=inicio;
    return inicio;
}

void insere (no *inicio, int teste) {
    int i;
    no *tmp, *aux;
    for (i=1; i<=teste; i++) {
       no *novo = (no*)malloc (sizeof(no));
       scanf("%s %d", &novo->nome, &novo->salt);
       getchar();
       novo->ant = NULL;
       if (inicio->tam==0) {
        novo->prox = NULL;
       }
       else {
         tmp = inicio->prox;
         tmp->ant = novo;
         novo->prox = tmp;
       }
       inicio->prox = novo;
       inicio->tam++;
    }
    aux  =  inicio->prox;
    tmp = inicio->prox;
     while (tmp->prox != NULL) {
        tmp = tmp->prox;
    }
    tmp->prox = aux;
    aux->ant = tmp;
    inicio->prox = tmp;
}

void pop (no *inicio) {
    no *tmp, *aux, *aux2;
    int i, x = inicio->prox->salt;
    while (inicio->tam!=1) {
        tmp = inicio->prox;
        aux = tmp->ant;
        aux2 = tmp->prox;
        for (i=1; i<=x; i++) {
            if (x % 2 != 0) tmp = tmp->ant;
            else tmp = tmp->prox;
            aux = tmp->ant;
            aux2 = tmp->prox;
        }
        aux->prox = aux2;
        aux2->ant = aux;
        x = tmp->salt;
        tmp->ant = NULL;
        tmp->prox = NULL;
        if (x%2==0) inicio->prox = aux;
        else inicio->prox = aux2;
        inicio->tam--;
    }
}