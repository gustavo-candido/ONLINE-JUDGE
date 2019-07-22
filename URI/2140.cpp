#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {2, 5, 10, 20, 50, 100}, n, m;
    vector<int>v;

    for(int i=0; i<6; i++) {
            for(int j=i; j<6; j++) {
                if(a[i] != a[j]) v.push_back(a[i]+a[j]);
            }
        }
    sort(v.begin(), v.end());
    while(cin >> n >> m && (n+m)) {
        if(binary_search(v.begin(), v.end(), m-n)) puts("possible");
        else puts("impossible");
    }
}
