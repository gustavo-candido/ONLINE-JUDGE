#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

main ()
{
    int M, N, c;
    long long int x, total;
    char A[20], text[10000];
    map <string, int> mymap;

    scanf("%d %d ", &M, &N);
    for (c=0; c<M; c++) {
        scanf("%s %lld", &A, &x);
        mymap.insert ( pair <string, long long int> (A, x));
    }
    map <string, long long int>::iterator key;
    getchar();
    for (c=0; c<N; c++) {
        total = 0;
        while (scanf("%s", text)) {
            if (text[0] == '.') break;
            else if (mymap.count (text)) {
                total+=mymap[text];
            }
        }
        printf("%d\n", total);
    }

}