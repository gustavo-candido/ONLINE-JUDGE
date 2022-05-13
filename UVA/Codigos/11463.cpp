#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int N, V, A, ori,dest, ans;
vector< vector<int> >box;

void Floyd_Warshall () {
	for(int i=0; i<V; i++) box[i][i]=0;
	for(int k=0; k<V; k++) {
		for(int i=0; i<V; i++) {
			for(int j=0; j<V; j++) {
				box[i][j] = min(box[i][j], box[i][k]+box[k][j]);
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	
	for(int c=0; c<N; c++) {
		scanf("%d %d", &V, &A);
		box.assign(V, vector<int>(V, INF));
		for(int i=0; i<A; i++) {
			scanf("%d %d", &ori, &dest);
			box[ori][dest]=1;
			box[dest][ori]=1;
		}
		Floyd_Warshall();
		scanf("%d %d", &ori, &dest);
		ans = -1;
		for(int i=0; i<V; i++) ans = max(ans, box[ori][i]+box[i][dest]);
		printf("Case %d: %d\n", c+1,ans);
		box.clear();
	} 
}
