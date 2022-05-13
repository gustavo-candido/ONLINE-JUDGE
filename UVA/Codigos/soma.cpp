#include <bits/stdc++.h>

using namespace std;

set<int>v;
int x, way;

int main ()
{
	int N;
	
	while(scanf("%d", &N)) {
		if(N==0)break;
		for(int i=0; i<N; i++){scanf("%d", &x);v.insert(x);}
		scanf("%d", &x);
		way=0;
		for(set<int>::iterator it=v.begin(); it!= v.end(); it++) {
			int i = *it;
			if(v.count(x-i) && x-i > i && i-x != i) way++;
		}
		printf("%d\n", way);
		v.clear();
	}
}

1 2 3 4 5 6 7 8 9 10
