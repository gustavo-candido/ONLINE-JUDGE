#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
    char A;
    struct tree *esq, *dir, *prox;
}tree;
int i;
void insere (tree *pai) {
    tree *tmp, *novo = (tree*)malloc(sizeof(tree));
    scanf("%c ", &novo->A);
    novo->dir = NULL;
    novo->esq = NULL;
    if (pai->prox == NULL) pai->prox = novo;
    else {
        tmp = pai->prox;
        while(1) {
            if (novo->A > tmp->A && tmp->dir == NULL) {
                tmp->dir = novo;
                break;
            }
            else if (novo->A > tmp->A && tmp->dir != NULL)
                tmp = tmp->dir;
            else if (novo->A < tmp->A && tmp->esq == NULL) {
                tmp->esq = novo;
                break;
            }
            else if (novo->A < tmp->A && tmp->esq != NULL)
                tmp = tmp->esq;
        }
    }
}

void prefixa (tree *pai) {
    if (pai != NULL) {
        if (i==0) {printf("%c", pai->A);i++;}
        else printf(" %c", pai->A);
        prefixa(pai->esq);
        prefixa(pai->dir);
    }
}
void infixa (tree *pai) {
    if (pai != NULL) {
        infixa(pai->esq);
        if (i==0) {printf("%c", pai->A);i++;}
        else printf(" %c", pai->A);
        infixa(pai->dir);
    }
}
void posfixa (tree *pai) {
    if (pai != NULL) {
        posfixa(pai->esq);
        posfixa(pai->dir);
        if (i==0) {printf("%c", pai->A);i++;}
        else printf(" %c", pai->A);
    }
}

void busca(tree *pai) {
    char chave;
    int x=0;
    tree *tmp = pai->prox;
    scanf("%c", &chave);
    while (x==0 && tmp != NULL) {
        if (chave > tmp->A) tmp = tmp->dir;
        else if (chave < tmp->A) tmp = tmp->esq;
        else { x=1; break;}
    }
    if (x==1) printf("%c existe\n", chave);
    else printf("%c nao existe\n", chave);
}

main ()
{
    char op[11];
    tree *pai = (tree*)malloc(sizeof(tree));
    pai->prox = NULL;

    while(scanf("%s", op) != EOF) {
        getchar();
        if (strcmp(op, "I") == 0) insere(pai);
        else if (strcmp(op, "INFIXA") == 0) {i=0;infixa(pai->prox);printf("\n");}
        else if (strcmp(op, "PREFIXA") == 0)  {i=0;prefixa(pai->prox);printf("\n");}
        else if (strcmp(op, "POSFIXA") == 0)  {i=0;posfixa(pai->prox);printf("\n");}
        else if (strcmp(op, "P") == 0) busca(pai);
    }
}