#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long int n, ans;
    vector<int> v;
    bitset<1000010> atk;
    cin >> n;
    atk.reset();
    v.resize(n);
    ans = 0;
    for(int i=0; i<n; i++) {cin >> v[i];ans+=v[i];}

    int i=0;
    while(1){
         atk[i] = 1;
        if(v[i])ans--;
        v[i]--;
        if(v[i] % 2 == 0) i++;
        else i--;

        if(i < 0 || i >= n) break;

    }
    cout << atk.count() << " " << ans << endl;
}
