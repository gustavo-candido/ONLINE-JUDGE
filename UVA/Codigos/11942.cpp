#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v, a;
	int n, aux;
	scanf("%d", &n);

	puts("Lumberjacks:");
	while(n--) {
		v.clear();
		a.clear();
		for(int j=0; j<10; j++){
			scanf("%d", &aux);	
			v.push_back(aux);
			a.push_back(aux);
		}
		sort(a.begin(), a.end());
		int i;
		for(i=0; i<v.size(); i++) {
			if(a[i] != v[i]) break;
		}
		if(i != v.size()) {
			reverse(a.begin(), a.end());
			for(i=0; i<v.size(); i++) {
				if(a[i] != v[i]) break;
		     	}
		}
		printf("%s\n", (i == v.size())?"Ordered":"Unordered");
	}
}
