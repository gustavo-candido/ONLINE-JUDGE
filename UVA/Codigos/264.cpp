#include <bits/stdc++.h>
using namespace std;

int main()
{
	int lim = 2,x, y, n;
	vector<int> num, den;	
	
	num.push_back(1);
	den.push_back(1);
	for(int i=1; i<=10000000;i++) {
		x = lim-1;
		y = 1;
		for(int j=1; j<lim; j++) {
			den.push_back(y);
			num.push_back(x);
			x--;
			y++;
			i++;
		}
		x = 1;
		y = lim;
		for(int j=lim; j>0; j--) {
			den.push_back(y);
			num.push_back(x);
			i++;
			x++;
			y--;
		}
		lim+=2;
	}
    while(scanf("%d", &n) != EOF) {
		printf("TERM %d IS %d/%d\n", n, num[n], den[n]);
	}
}
