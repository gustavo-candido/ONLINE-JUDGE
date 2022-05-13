#include <bits/stdc++.h>
using namespace std;

int n, b, tiket, pass[30], money[30], s[30], e[30];

int f(int id, int *line) {
	if(id >= tiket) return 0;
	bool go = 1;
	for(int i=e[id]; i<s[id]; i++) {
		line[i]+=pass[id];
		if(line[i] > n) go = 0;
	}
	int aux = 0;
	if(go) aux = max(aux,f(id+1, line)+money[id]);

	for(int i=e[id]; i<s[id]; i++) line[i]-=pass[id];
	return max(aux, f(id+1, line));
}

int main()
{
	int line[30];
	memset(line, 0 ,sizeof line);
	while(scanf("%d %d %d", &n, &b, &tiket) && n+b+tiket) {
		for(int i=0; i<tiket; i++) {
			scanf("%d %d %d", &e[i], &s[i], &pass[i]);
			money[i] = (s[i] - e[i]) * pass[i];
		}
		printf("%d\n", f(0, line));
	}	
}
