#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, maxi, C=0;
	vector<string> v;
	vector<int>x(10);
	string url;
	cin >> n;

	while(n--) {
		printf("Case #%d:\n", ++C);
		v.clear();
		maxi = -1;
		for(int i=0; i<10; i++){
			cin >> url >> x[i];
			v.push_back(url);
			if(x[i] > maxi) maxi = x[i];
		}
		for(int i=0; i<10; i++){
			if(maxi == x[i]) cout << v[i] << endl;
		}
	}
}
