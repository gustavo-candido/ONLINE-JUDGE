#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	int n = -1;
	double score=-1;
	double x, y;
	cin >> t;
	while(t--) {
		cin >> x >> y;
		if(y > score) {
			n = x; score = y;
		}
	}
	if(score < 8) cout << "Minimum note not reached\n";
	else cout << n << endl;
}