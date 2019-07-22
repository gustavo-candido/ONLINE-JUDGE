#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n, x;

    while(getline(cin, s) && !cin.eof()) {
        scanf("%d", &n);

        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            printf("%c", s[x-1]);
        }
        getchar();
        puts("");
    }
}
