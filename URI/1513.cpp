#include <bits/stdc++.h>
#define F first
#define S second
#define inf 0x3F3F3F3F
using namespace std;

typedef pair<int, int> ii;

char box[110][110];
int N, M, K, dis[20][20], dp[18][1<<18], vis[110][110], id[20][20], x[20], y[20];
int dr[]={-1, -2, -2, -1, 1, 2, 2, 1};
int dc[]={2, 1, -1, -2, -2, -1, 1, 2};

bool valida(int i, int j){ return i>=0 && j>=0 && i<N && j<M && box[i][j]!='#'; }

void bfs(int ini) {
	queue<ii> q;
	q.push(ii(x[ini], y[ini]));
	memset(vis, -1, sizeof vis);
	dis[ini][ini] = 0;
	vis[x[ini]][y[ini]] = 0;
	ii v, nxt;
	while(q.size()) {
		v = q.front(); q.pop();
		for(int i=0; i<8; i++) {
			nxt = ii(v.F+dr[i], v.S+dc[i]);
			if(!valida(nxt.F, nxt.S))continue;
			if(vis[nxt.F][nxt.S] == -1) {
                vis[nxt.F][nxt.S] =  vis[v.F][v.S]+1;
                q.push(nxt);
			}
		}
	}
    for(int i=0; i<=K; i++){
        dis[ini][i] = vis[x[i]][y[i]];
    }
}


int tsp(int u, int bit) {
	if(bit == (1 << K)-1) return dis[u][0];
	int &p = dp[u][bit];
	if(p != -1) return p;
	int ans = 1e9;
	for(int i=1; i<K; i++) {
		if(bit & (1 << i)) continue;
		ans = min(ans, tsp(i, bit|(1<<i))+dis[u][i]);
	}
	return p = ans;
}



int main(){
	while(scanf("%d %d %d", &N, &M, &K), N, M, K){
		getchar();
		int k=1;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				scanf("%c", &box[i][j]);
				if(box[i][j]=='P') id[i][j] = k, x[k] = i, y[k++] = j;
				if(box[i][j]=='C') id[i][j] = 0, x[0] = i, y[0] = j;
			}
			getchar();
		}
		for(int i=0; i<=K; i++)bfs(i);

		K++;
		memset(dp, -1, sizeof(dp));
		printf("%d\n", tsp(0, 1));

	}
}
