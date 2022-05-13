#include <bits/stdc++.h>
#define INF 1e15
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

int dr[3] = {-1, 0, 1};
int dc[3] = {1,  1, 1};

int n, m, dp[105][105];
ll box[105][105], dis[105][105], ans;

void f(int r, int c) {
	if(c == m-1) {
		ans = min(ans, dis[r][c]);
		return;
	}
	if(c >= m) return;
	
	for(int i=0; i<3; i++) {
		int x = r+dr[i];
		int y = c+dc[i];
		if(x == -1) x = n-1;
		if(x == n) x = 0;
		if(dis[r][c] + box[x][y] < dis[x][y]) {
			dis[x][y] = dis[r][c] + box[x][y];
			f(x, y);
		}
	}
}

void bt (int r, int c) {
	if(c <= -1 || dp[r][c]) return;
	
	dp[r][c] = 1;
	for(int i=0; i<3; i++) {
		int x = r-dr[i];
		int y = c-dc[i];
		if(x == -1) x = n-1;
		if(x == n) x = 0;
		if(dis[r][c] - box[r][c] == dis[x][y]) bt(x, y);
	}

}
void ff(int r, int c) {
	
	if(c == m-1) {printf("%d\n", r+1);return;}
	printf("%d ", r+1);
	vector<ii> go;
	for(int i=0; i<3; i++) {
		int x = r+dr[i];
		int y = c+dc[i];
		if(x == -1) x = n-1;
		if(x == n) x = 0;
		if(dis[r][c] + box[x][y] == dis[x][y] && dp[x][y]) {
			go.push_back(ii(x, y));
		}
	}
	ii mini = ii(go[0].F, go[0].S);
	if(go.size() > 1) {
		for(int i=0; i<go.size(); i++) {
			mini.F = min(mini.F, go[i].F);
			mini.S = min(mini.S, go[i].S);
		}
	}

	ff(mini.F, mini.S);
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				scanf("%lld", &box[i][j]);
				dis[i][j] = INF;
			}
		}
		
		memset(dp, 0, sizeof dp);
		ans = INF;
		ll line = -1, aux = INF;
		for(int i=0; i<n; i++) {
			dis[i][0] = box[i][0];
			f(i, 0);
			if(aux != ans) {
				line = i; 
				aux = ans;
			}
		}
		for(int i=0; i<n; i++) if(dis[i][m-1] == ans)bt(i, m-1);	
		
		ff(line, 0);
		printf("%lld\n", ans);
		
	}
}
