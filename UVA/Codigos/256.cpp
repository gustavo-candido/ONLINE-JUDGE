#include <bits/stdc++.h>
using namespace std;

int dig;

vector< vector<int> > ans;

int main()
{
	ans.resize(10);
	int x, p1, p2;
	for(int i = 0; i<100; i++) {
		x = i;
		p1 = x / 10;
		p2 = x - p1*10;

		if((p1+p2)*(p1+p2) == x) ans[2].push_back(x);
			
	}
	for(int i = 0; i<10000; i++) {
		x = i;
		p1 = x / 100;
		p2 = x - p1*100;

		if((p1+p2)*(p1+p2) == x) ans[4].push_back(x);
	}
	for(int i = 0; i<1000000; i++) {
		x = i;
		p1 = x / 1000;
		p2 = x - p1*1000;

		if((p1+p2)*(p1+p2) == x) ans[6].push_back(x);
	}
	for(int i = 0; i<100000000; i++) {
		x = i;
		p1 = x / 10000;
		p2 = x - p1*10000;
		
		if((p1+p2)*(p1+p2) == x) ans[8].push_back(x);
	}
	while(scanf("%d", &dig) != EOF) {
		for(int i=0; i<(int)ans[dig].size(); i++) {
			if(dig == 2)printf("%.2d\n", ans[dig][i]);
			if(dig == 4)printf("%.4d\n", ans[dig][i]);	
			if(dig == 6)printf("%.6d\n", ans[dig][i]);
			if(dig == 8)printf("%.8d\n", ans[dig][i]);
		}	
	}
}
