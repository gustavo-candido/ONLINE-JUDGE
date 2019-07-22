#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int num;
	struct tree *dir,*esq;
} tree;

tree *cria () {
	tree *mytree = (tree*) malloc (sizeof(tree));
	mytree->esq = NULL;
	mytree->dir = NULL;
	return mytree;
}
void insere (tree *pai) {
	tree *tmp, *novo = (tree*) malloc (sizeof(tree));
	novo->esq = NULL;
	novo->dir = NULL;
	scanf("%d", &novo->num);
	if (pai->esq == NULL) {
		pai->esq = novo;
	}
	else {
		tmp = pai->esq;
		while (1) {
			if (novo->num > tmp->num && tmp->dir == NULL) {
				tmp->dir = novo;
				break;
			}
			else if (novo->num > tmp->num && tmp->dir != NULL) {
				tmp = tmp->dir;
			}
			else if (novo->num < tmp->num && tmp->esq == NULL) {
				tmp->esq = novo;
				break;	
			}
			else if (novo->num < tmp->num && tmp->esq != NULL) {
				tmp = tmp->esq;
			}
		}
	}
}

void infixa (tree *tmp) {
	if (tmp != NULL) {
		infixa (tmp->esq);
		printf(" %d", tmp->num);
		infixa (tmp->dir);
	}
}
void prefixa (tree *tmp) {
	if (tmp != NULL) {
		printf(" %d", tmp->num);
		prefixa (tmp->esq);
		prefixa (tmp->dir);
	}
}
void posfixa (tree *tmp) {
	if (tmp != NULL) {
		posfixa (tmp->esq);
		posfixa (tmp->dir);
		printf(" %d", tmp->num);
	}
}



int main ()
{
	int NC,C, N, c;
	tree *pai;
	scanf("%d", &NC);
	for (C=0;C<NC;C++) {
		scanf("%d", &N);
		pai = cria();
		for (c=0; c<N; c++) {
			insere(pai);
		}
		printf("Case %d:\n", C+1);
		printf("Pre.:");
		prefixa(pai->esq);
		printf("\n");
		printf("In..:");
		infixa(pai->esq);
		printf("\n");
		printf("Post:");
		posfixa(pai->esq);
		printf("\n\n");
		
	}
}