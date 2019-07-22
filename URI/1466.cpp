#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <list>
using namespace std;

typedef struct dup {
    int key, val;
}dup;
list<dup> level;
list<dup>::iterator it;

typedef struct tree {
    int num, nivel;
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
    int cont = 1;
    novo->esq = NULL;
    novo->dir = NULL;
    scanf("%d", &novo->num);
    if (pai->esq == NULL) {
        pai->esq = novo;
        novo->nivel = cont;
    }
    else {
        cont++;
        tmp = pai->esq;
        while (1) {
            if (novo->num > tmp->num && tmp->dir == NULL) {
                tmp->dir = novo;
                novo->nivel = cont;
                break;
            }
            else if (novo->num > tmp->num && tmp->dir != NULL) {
                tmp = tmp->dir;
                cont++;
            }
            else if (novo->num < tmp->num && tmp->esq == NULL) {
                tmp->esq = novo;
                novo->nivel = cont;
                break;
            }
            else if (novo->num < tmp->num && tmp->esq != NULL) {
                tmp = tmp->esq;
                cont++;
            }
        }
    }
}

bool compara (dup a,  dup b) {
    if (a.key < b.key) return true;
    else if (a.key > b.key) return false;
    else {
        if (a.val < b.val) return true;
        else if (a.val > b.val) return false;
        else return true;
    }
}

void prefixa (tree *tmp) {
    dup teste;
    if (tmp != NULL) {
        teste.key = tmp->nivel;
        teste.val = tmp->num;
        level.push_back(teste);
        prefixa (tmp->esq);
        prefixa (tmp->dir);
    }
}

int main ()
{
    int NC, N, i;
    tree *pai;
    scanf("%d", &NC);

    for (int c=0; c<NC; c++) {
        pai = cria();
        scanf("%d", &N);
        for (int i=0; i<N; i++) {
            insere(pai);
        }
        prefixa(pai->esq);
        level.sort(compara);
        printf("Case %d:\n", c+1);
        for (i=0, it = level.begin(); it != level.end(); it++, i++) {
            if (i+1 != level.size())printf("%d ", it->val);
            else printf("%d", it->val);
        }
        printf("\n\n");
        level.clear();
    }
}

