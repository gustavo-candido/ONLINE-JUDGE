#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct aluno {
    char nome[100], cor[100], tam[2];
};

int compare(const void*a, const void*b){
    int c = strcmp ((*(struct aluno*)a).cor, (*(struct aluno*)b).cor);
    int ta = strcmp ((*(struct aluno*)a).tam, (*(struct aluno*)b).tam);
    int n = strcmp ((*(struct aluno*)a).nome, (*(struct aluno*)b).nome);
    if(c < 0) return -1;
    else if(c > 0) return 1;
    else{
        if(ta > 0) return -1;
        else if(ta < 0) return 1;
        else{
            if(n > 0) return 1;
            else if(n < 0) return -1;
            else return 0;
        }
    }
}
int main ()
{
    int N, c, i, j, x=0;

    while (scanf("%d", &N) != EOF) {
        if (N==0) break;
            struct aluno A[N];
        for (i=0; i<N; i++) {
            getchar();
           gets(A[i].nome);
            scanf("%s %s", A[i].cor, A[i].tam);
        }
        qsort(A, N, sizeof(struct aluno), compare);
        if (x>0) printf("\n");
        for (i=0; i<N; i++) {
            printf("%s %s %s\n", A[i].cor, A[i].tam, A[i].nome);
        }
        x++;
    }
}