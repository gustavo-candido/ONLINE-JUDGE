#include <bits/stdc++.h>
#define LSOne(s)( s & (-s))
using namespace std;

int v[100010], bit[100010];
int N;
int aux;

int sum(int i) {
    int sum=0;
    for(; i; i-=LSOne(i))sum+=bit[i];
    return sum;
}
void upp(int i, int val){
    for(; i < N; i+=LSOne(i)) bit[i]+=val;
}

int main()
{
    char op;
    scanf("%d", &N);
    memset(bit, 0, sizeof(int)*(N+1));
    for(int i=1; i<=N; i++) {
        scanf("%d", &v[i]);
        upp(i, v[i]);
    }
    getchar();

    while(scanf("%c %d", &op, &aux) != EOF) {
        getchar();
        if(op == 'a') {
            upp(aux, -v[aux]);
            v[aux] = 0;
        }
        else {
            printf("%d\n", sum(--aux));
        }
    }
}
