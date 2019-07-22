#include <bits/stdc++.h>
using namespace std;

int main()
{
	bitset<1003> b;
	int q, e, x;

	cin >> q >> e;

	while(e--) {
		cin >> x;
		b[x] = 1;
	}
	while(q--) {
		cin >> x;
		if(b[x]) puts("0");
		else puts("1");
		b[x] = 1;
	}
}