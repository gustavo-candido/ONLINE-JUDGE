#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> s;
    string  pok;
    int n;

    scanf("%d", &n);
    getchar();
    while(n--) {
        getline(cin, pok);
        s.insert(pok);
    }
    printf("Falta(m) %d pomekon(s).\n", 151-s.size());
}
