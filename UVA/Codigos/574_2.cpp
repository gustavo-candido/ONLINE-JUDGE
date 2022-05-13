#include <bits/stdc++.h>
using namespace std;

int t, n, v[20];
set< vector<int> > vis;
bool g;

void solution(int ans) {
	g = 1;
	vector<int> vet;
	for(int i=1; i<=n; i++) 
		if(ans&(1<<i)) vet.push_back(v[i]);
	if(vis.count(vet)) return;
	printf("%d", vet[0]);
	for(int i=1; i<vet.size(); i++) printf("+%d", vet[i]);
	puts("");
	vis.insert(vet);
	return;
}
void f(int k, int id,int ans) {
	if(k == t) {
		solution(ans);
		return;
	}
	if(k > t || id > n) return;

	f(k+v[id], id+1, ans|(1<<id));
	f(k, id+1, ans);
	return;
}
int main()
{
	while(scanf("%d %d", &t, &n) != EOF && t+n) {
		for(int i=1; i<=n; i++) scanf("%d", &v[i]);
		vis.clear();
		g = 0;
		printf("Sums of %d:\n", t);
		f(0, 1, 0);
		if(!g) puts("NONE");
	}	
}
