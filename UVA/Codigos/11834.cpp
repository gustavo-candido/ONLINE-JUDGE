#include <bits/stdc++.h>
using namespace std;

int main()
{
	int L, C, R1, R2;
	while(cin >> L >> C >> R1 >> R2 && !cin.eof() && L && C && R1 && R2) {
		if(R1*2 > min(L,C) || R2*2 > min(L,C)) puts("N");
		else if (hypot(L - R2 - R1, C - R2 - R1) >= R1+R2) puts("S");
		else puts("N");
	}
}
