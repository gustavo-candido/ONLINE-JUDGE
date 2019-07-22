#include <bits/stdc++.h>
using namespace std;

int divi[2000010];
int ans[2000010];

void sieve() {
    for(int i=1; i<2e6+5; i++)
        divi[i] = 1;

	for(int i=2; i<2e6+5; i++)
        for(int j=i; j<2e6+5; j+=i)
            divi[j]++;


	ans[0] = ans[1] = 0;
	for(int i=2; i<2e6+5; i++)
        ans[i] = ans[i-1] + ((divi[divi[i]] == 2)?1:0);
}

int main(){
    sieve();
    int n;
    
    std::ios::sync_with_stdio(false);
    while(cin >> n && !cin.eof()) {
        cout << ans[n] << "\n";
    }
}
