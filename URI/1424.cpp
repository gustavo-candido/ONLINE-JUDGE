#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

int main ()
{
    int N, M, aux, aux2;
    map < int, vector<int> > vetor;
    while (scanf("%d %d", &N, &M) != EOF) {
        vetor.clear();
        for (int i=1; i<=N; i++) {
            scanf("%d", &aux);
            if (!vetor.count(aux)) vetor[aux] = vector<int>();
                vetor[aux].push_back(i);
        }
        for (int i=0; i<M; i++) {
            scanf("%d %d", &aux, &aux2);
            if (!vetor.count(aux2) || vetor[aux2].size() < aux) printf("0\n");
            else printf("%d\n", vetor[aux2][aux-1]);
        }
    }
}
