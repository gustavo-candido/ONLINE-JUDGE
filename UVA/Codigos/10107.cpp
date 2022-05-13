#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x;
	vector<int> v;

	while(scanf("%d", &x) != EOF) {
		v.push_back(x);
		stable_sort(v.begin(), v.end());
		if(v.size()%2 == 0) {
			
			printf("%d\n", (v[(int)v.size()/2]+v[(int)v.size()/2-1])/2);
		}
		else printf("%d\n", v[(int)(v.size()/2)] );
	}	
}
