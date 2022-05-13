#include <bits/stdc++.h>
using namespace std;


int main()
{
	int N, a, b, c, n, ans;
	cin >> N;

	while(N--) {
		cin >> n;
		ans = 0;
		while(n--) {
			cin >> a >> b >> c;
			ans+=a*c;
		}
		cout << ans << endl;
	}
}
