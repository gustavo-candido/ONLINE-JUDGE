#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, a, j;
    bitset<100050>A,B;

    while(scanf("%d %d", &N, &M) && N+M != 0) {
        A.reset(); B.reset();
        for(int i=0; i<N; i++) {
            scanf("%d", &a);
            A[a]=1;
            if(a > j) j = a;
        }
        for(int i=0; i<M; i++) {
            scanf("%d", &a);
            B[a]=1;
            if(a > j) j = a;
        }
        for(int i=0; i<=j; i++)
            if(A[i] && B[i]){
                A[i] = B[i] = 0;
            }

        printf("%d\n", min(A.count(), B.count()));
    }
}
