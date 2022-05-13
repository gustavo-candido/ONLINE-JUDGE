#include <bits/stdc++.h>
using namespace std;

string s, rs;
int n, b[100001];

void kmp_pre(){
	n = s.size();
	int i = 0, j = -1; b[0] = -1;

	while(i < n) {
		while(j >= 0 && rs[i] != rs[j]) j = b[j];
		i++, j++;
		b[i] = j;
	}
}

void kmp(){
	n = s.size();
	int i = 0, j = 0;
	int math = 0;
	while(i < n) {
		while(j >= 0 && s[i] != rs[j]) j = b[j], math = j+1;
		math = max(math, j+1);
		i++, j++;
	}
	cout << s;
	for(i = math; i<n; i++) printf("%c", rs[i]);puts("");
}

int main()
{
	while(getline(cin, s)){
		rs = s;
		reverse(rs.begin(), rs.end());
		kmp_pre();
		kmp();
	}
}
