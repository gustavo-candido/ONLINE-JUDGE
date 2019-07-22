#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
    int num;
    struct tree *esq, *dir;
}tree;

int i = 0;

void insere (tree *pai, int x) {
    tree *tmp, *novo = (tree*)malloc(sizeof(tree));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->num = x;
    if (pai->dir == NULL) pai->dir = novo;
    else {
        tmp = pai->dir;
        while(1) {
            if (novo->num > tmp->num && tmp->dir == NULL) {
                tmp->dir = novo;
                break;
            }
            else if (novo->num > tmp->num && tmp->dir != NULL)
                tmp = tmp->dir;
            else if (novo->num < tmp->num && tmp->esq == NULL) {
                tmp->esq = novo;
                break;
            }
            else if (novo->num < tmp->num && tmp->esq != NULL)
                tmp = tmp->esq;
        }
    }
}
void busca (tree *pai, int y) {
    tree *tmp = pai->dir;
    int key, x=0;
    key = y;
    while (tmp != NULL && x==0) {
        if (key > tmp->num) tmp = tmp->dir;
        else if (key < tmp->num) tmp = tmp->esq;
        else {x=1;break;}
    }
    if (x==1) printf("%d existe\n", key);
    else printf("%d nao existe\n", key);
}

void remove (tree *pai, int y) {
    tree *tmp = pai->dir, *ant, *aux;
    int key, x=0;
    key = y;
    while (tmp != NULL && x==0) {
        if (key > tmp->num) {ant = tmp;tmp = tmp->dir;}
        else if (key < tmp->num){ant = tmp;tmp = tmp->esq;}
        else {x=1;break;}
    }
    if (x==1) {
        if (tmp->esq == NULL && tmp->dir == NULL) {
			if (pai->dir != tmp) {
                if (ant->dir == tmp) ant->dir = NULL;
                else ant->esq = NULL;
			}
			else pai->dir = NULL;
        }
        else if ((tmp->esq != NULL && tmp->dir == NULL) || (tmp->esq == NULL && tmp->dir != NULL)) {
            if (pai->dir == tmp) {
                if (tmp->dir != NULL) {
                    pai->dir = tmp->dir;
                }
                else pai->dir = tmp->esq;
            }

			if (tmp->esq != NULL && ant->esq == tmp) {
				ant->esq = tmp->esq;
				tmp->esq = NULL;
			}

			else if (tmp->esq != NULL && ant->dir == tmp) {
				ant->dir = tmp->esq;
				tmp->dir = NULL;
			}

			if (tmp->dir != NULL && ant->esq == tmp) {
				ant->esq = tmp->dir;
				tmp->esq = NULL;
			}

			else if (tmp->dir != NULL && ant->dir == tmp) {
				ant->dir = tmp->dir;
				tmp->dir = NULL;
			}
		}

        else if (tmp->esq != NULL && tmp->dir != NULL) {
            aux = tmp;
            ant = tmp;
            tmp = tmp->esq;
            if (tmp->dir != NULL) {
                while(tmp->dir != NULL) {
                    ant = tmp;
                    tmp = tmp->dir;
                }
                aux->num = tmp->num;
                ant->dir = tmp->esq;
            }

            else {
                aux->num = tmp->num;
                ant->esq = tmp->esq;
            }
		}
    }
}

void prefixa (tree *pai) {
    if (pai != NULL) {
        if (i==0) {printf("%d", pai->num);i++;}
        else printf(" %d", pai->num);
        prefixa(pai->esq);
        prefixa(pai->dir);
    }
}
void infixa (tree *pai) {
    if (pai != NULL) {
        infixa(pai->esq);
        if (i==0) {printf("%d", pai->num);i++;}
        else printf(" %d", pai->num);
        infixa(pai->dir);
    }
}
void posfixa (tree *pai) {
    if (pai != NULL) {
        posfixa(pai->esq);
        posfixa(pai->dir);
        if (i==0) {printf("%d", pai->num);i++;}
        else printf(" %d", pai->num);
    }
}
int main ()
{
    tree *pai = (tree*) malloc (sizeof(tree));
    char aux[20000], *aux2;
    int x;
    pai->dir = NULL;
    pai->esq = NULL;

    while (gets(aux) != NULL) {
        if (aux[1] == ' ') {
            aux2 = strtok (aux, " ");
            aux2 = strtok (NULL, " ");
            x = atoi (aux2);
            if (strcmp(aux, "I") == 0) insere(pai, x);
            else if (strcmp(aux, "P") == 0) busca(pai, x);
            else if (strcmp(aux, "R") == 0) remove(pai, x);
        }
        else {
            if (strcmp(aux, "INFIXA") == 0) {i=0;infixa(pai->dir);printf("\n");}
            else if (strcmp(aux, "PREFIXA") == 0) {i=0;prefixa(pai->dir);printf("\n");}
            else if (strcmp(aux, "POSFIXA") == 0) {i=0;posfixa(pai->dir);printf("\n");}
        }
    }
}
