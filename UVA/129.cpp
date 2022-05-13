#include <bits/stdc++.h>
using namespace std;

string ans;
int n, l;

bool sub(string s) {
	string aux = s;
	while(aux.size()) {
		cout << aux << endl;
		aux = aux.substr(1);
	}
	aux = s;
	while(aux.size()) {
		cout << aux << endl;
		aux.erase(aux.size()-1);
	}
}
void f(string s) {
	if(ans.size() == n) return;
	
	string att, next;
	for(int i=0; i<s.size(); i++) {
		for(int j=i+1; j<s.size(); j++){
			att = s.substr(i, j);
			//next = s.substr()
		}
	}
	if(s.size() > ans.size()) ans = s;
	for(int i='A'; i<'A'+n; i++) {
		if(ans.size() == n) return;
		s.push_back((char)i);
		f(s);
		s.erase(s.size()-1);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	sub(s);
}
