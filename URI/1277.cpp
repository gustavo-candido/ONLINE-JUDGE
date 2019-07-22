#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a, b;
    char name[105][55], freq[105][1000];
    vector<string> ans;

    scanf("%d", &t);

    while(t--) {
            ans.clear();
            scanf("%d", &n);
            getchar();

            for(int i=0; i<n; i++)
                scanf("%s", name[i]);
            for(int i=0; i<n; i++)
                scanf("%s", freq[i]);

            for(int i=0; i<n; i++) {
                a = b = 0;
                for(int j=0; j<(int)strlen(freq[i]); j++) {
                    if(freq[i][j] == 'P') a++, b++;
                    else if(freq[i][j] == 'A') b++;
                }
                if((double)a / (double) b < 0.75) ans.push_back(name[i]);
            }

            bool f = 0;
            for(int i = 0; i < (int)ans.size(); i++) {
                if(f) printf(" ");
                f = 1;
                cout << ans[i];
            }
            puts("");
    }
}
