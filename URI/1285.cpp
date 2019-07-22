#include <stdio.h>
#include <set>
using namespace std;

int main ()
{
    int N, M, x;
    char A[10];
    set<int> repeat;

    while(scanf("%d %d", &N, &M) != EOF) {
        x=-1;
        for (int i=N; i<=M; i++) {
            if (!repeat.count(i)) {
                int count[10] = {0};
                sprintf(A, "%d", i);
                for(int j=0; A[j]!='\0'; j++) {
                    if (count[(int)A[j]-48] != 0) {
                        repeat.insert(i);
                        x++;
                        break;
                    }
                    count[(int)A[j]-48]++;
                }
            }
            else x++;
        }
        printf("%d\n", M-N - x);
    }
}
