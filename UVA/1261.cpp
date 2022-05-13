#include <bits/stdc++.h>
using namespace std;

map<string, bool> dp;
bool f(string s) {
	if(!s.size()) return true;
	if(dp.count(s)) return dp[s];
	bool ans = false;
	
	for(int i=0; i < (int)s.size()-1; i++) {
		if(s[i] == s[i+1]) {
			string aux;
			for(int j=0; ; j++) {
				if(i == j) {
					while(j < s.size() && s[i] == s[j]) j++;
				}
				if(j >= s.size())break;
				aux.push_back(s[j]);
			}
			ans|=f(aux);	
			while(i < (int)s.size()-1 && s[i] == s[i+1]) i++;
		}
	}
	return dp[s] = ans;
}

int main()
{
	int t;
	string s;
	scanf("%d", &t);
	getchar();
	while(t--) {
		getline(cin, s);
		if(f(s)) puts("1");
		else puts("0");
	}
}

	
