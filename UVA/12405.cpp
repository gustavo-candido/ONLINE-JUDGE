#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
	int t, n, ans, C=1;
	string field;

	cin >> t;

	while(t--) {
		ans=0;
		cin >> n;
		getchar();
		getline(cin, field);
		for(int i=1; i<n; i++) {
			if(field[i-1] == '.') {ans++;field[i-1] = field[i] = field[i+1] = '#';i+=2;}
		}
		if(field[n-1] == '.')ans++;
		printf("Case %d: %d\n" , C++, ans);
	}
}
