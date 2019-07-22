#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, ans;
    string a, b;
    cin >> T;

    while(T--) {
        cin >> a >> b;
        ans=0;
        for(int i=0; i<(int)a.size(); i++) {
            if(a[i] <= b[i]) ans+=(b[i]-a[i]);
            else ans+= (('z' - a[i]+1) + (b[i] - 'a'));
        }
        cout << ans << endl;
    }
}
