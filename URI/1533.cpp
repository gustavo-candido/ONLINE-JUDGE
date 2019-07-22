#include <stdio.h>
#include <map>
using namespace std;

int main ()
{
    int N, V;
    map <int, int> mymap;
    map <int, int>::reverse_iterator it;
    while(scanf("%d", &N), N!=0) {
        for (int i=1; i<=N; i++) {
            scanf("%d", &V);
            mymap.insert(pair<int, int> (V, i));
        }
        it = mymap.rbegin();
        it++;
        printf("%d\n", it->second);
        mymap.clear();
    }
}