#include <bits/stdc++.h>
using namespace std;

int T, A, B, mem[10010];

int rev(int x) {
	if(mem[x] != -1) return mem[x];
	char a[20], b;

	sprintf(a, "%d", x);
	for(int i=0; i<strlen(a)/2; i++) {
		b = a[i];
		a[i] = a[strlen(a)-1-i];
		a[strlen(a)-1-i] = b;
	}
	return mem[x] = atoi(a);
}

int bfs()
{
	int v, x;
	int dis[10050];
	queue<int>q;
	q.push(A);
    memset(dis, -1, sizeof dis);dis[A] = 0;
	while(q.size()) {
		v = q.front(); q.pop(); x = rev(v);
        if(v > 10000) continue;
		if(dis[v+1] == -1) {
			dis[v+1] = dis[v]+1;
			q.push(v+1);
		}
		if(dis[x] == -1) {
			dis[x] = dis[v]+1;
			q.push(x);
		}
		if(v == B) break;

	}
	return dis[B];
}

int main(){
	scanf("%d", &T);
	memset(mem, -1, sizeof mem);
	while(T--) {
		scanf("%d %d", &A, &B);
		printf("%d\n", bfs());
	}
}
