#include <bits/stdc++.h>
using namespace std;

int main()
{
	long double d, vf, vg;


	while(cin >> d >> vf >> vg) {
		if(cin.eof()) break;
		long double t1 = 12*vg*12*vg;
		long double t2 = (d*d+144)*vf*vf;

		if(t2 <= t1) puts("S");
		else puts("N");
	}
}