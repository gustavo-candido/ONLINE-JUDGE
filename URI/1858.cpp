#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int v[101], t, a=0;
    cin >> t;
 
    for(int i=0; i<t; i++) {
        cin >> v[i];
	if(v[a] > v[i]) a = i;
    }
    cout << a+1 << endl;
    return 0;
}