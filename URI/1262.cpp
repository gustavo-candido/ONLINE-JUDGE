#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[55];
    int sz, ans, x;

    while(gets(s) != NULL) {
        scanf("%d", &sz);
        getchar();
        ans=x=0;

        for(int i=0; i<(int)strlen(s); i++) {
            if(s[i] == 'W') {
                x=0;
                ans++;
            }
            else if(s[i] == 'R') {
                x++;
                if(x == 1) {
                    ans++;
                }
                if(x > sz) {
                    x-=sz;
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
}
