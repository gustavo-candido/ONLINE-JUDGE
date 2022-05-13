///TLE
#include <bits/stdc++.h>
#define INF 200000000
using namespace std;

int box[5000][5000];
queue< pair<int,int> > q;
map<pair<int,int>, int > dist;
set< pair<int,int> > s;
int ori, dest, p, maxi, ans;
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

void print() {
	for(int i=0; i<=maxi; i++) {
		for(int j=0; j<=maxi;j++) {
			printf(" %d", box[i][j]);
		}
		printf(" ||| ");
		for(int j=0; j<=maxi; j++) {
				if( dist.count(make_pair(i,j)))printf(" %.3d", dist[make_pair(i,j)]);
				else printf(" INF");
		}puts("");
	}
	puts("");
}

int bfs() {
	ans = 200000000;
	if(s.count(make_pair(ori,dest)))dist[make_pair(ori,dest)]=0;
	q.push(make_pair(ori,dest));
	while(q.size()) {
		pair<int,int> fronte = q.front();q.pop();
		int R = fronte.first, C = fronte.second;
		if(box[R][C]==1) ans = min(ans,dist[make_pair(R,C)]);
		for(int i=0; i<4; i++) {
			int r = R+dr[i], c = C+dc[i];
			if(!(r < 0 || c < 0 || r >maxi || c > maxi)){
				if(!dist.count(make_pair(r,c))) {
					if(s.count(make_pair(r,c)))dist[make_pair(r,c)]=0;
					else dist[make_pair(r,c)]=dist[make_pair(R,C)]+1;
					q.push(make_pair(r,c));
				}
				else if(dist[make_pair(R,C)]+1 < dist[make_pair(r,c)]) {
					dist[make_pair(r,c)]=dist[make_pair(R,C)]+1;
					q.push(make_pair(r,c));
				}
			}
				
		}
	}
	return ans;
}

int main()
{
	while(scanf("%d", &p) && p) {
		memset(box,0,sizeof(box));
		maxi = -200000000;
		ans = INF;
		for(int i=0; i<p; i++) {
			scanf("%d %d", &ori, &dest);
			box[ori][dest] = 1;
			maxi = max(maxi, max(ori,dest));
		}
		scanf("%d", &p);
		for(int i=0; i<p; i++) {
			scanf("%d %d", &ori, &dest);
			s.insert(make_pair(ori,dest));
			box[ori][dest] = 2;
			maxi = max(maxi, max(ori,dest));
		}
		bfs();
		printf("%d\n", ans);
		s.clear();
		dist.clear();
	}
}
