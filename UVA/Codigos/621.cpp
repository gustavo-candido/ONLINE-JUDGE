#include <bits/stdc++.h>
using namespace std;


int main()
{
	int N;
	string a;
	cin >> N;

	while(N--) {
		cin >> a;
		if(a[0] == '9' && a[a.size()-1] == '4') puts("*");
		else if(a.size() > 1 && a[a.size()-1] == '5' && a[a.size()-2] == '3') puts("-");
		else if(a.size() > 2 && a[0] == '1' && a[1] == '9' && a[2] == '0') puts("?");
		else puts("+"); 
	}
}
