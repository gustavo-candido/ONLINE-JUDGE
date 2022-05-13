#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a;
	vector<char> ans;
	getline(cin, a);
	a = "";
	while(getline(cin, a)) {
		if(a.compare("___________") == 0) break;
		int n=0, sum=0;
		for(int i = a.size()-2; i>=1; i--) {
			if(a[i] == 'o') sum+=pow(2,n);
			if(a[i] == '.') n--; 
			n++;
		}
		ans.push_back((char)sum);
	}
	for(int i=0; i<(int)ans.size(); i++) cout << ans[i];
}
