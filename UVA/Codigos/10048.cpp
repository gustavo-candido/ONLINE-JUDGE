	#include<bits/stdc++.h>
	using namespace std;

	int C,S,Q, maxi, ori, dest, w;
	vector< pair< int, pair<int,int> > > edge;
	map<int, vector< pair<int,int> > > box;
	vector<int>A, vis, p;
	vector< vector<int> >min_max;
	bool x;


			
	void inicia() {
		A.resize(C+1);
		min_max.assign(C+1, vector<int>(C+1, -1));
		for(int i=0; i<=C; i++)A[i]=i;
	}

	int find(int i) {
		if(A[i] == i) return i;
		else return A[i] = find(A[i]);
	}

	bool mesma(int i, int j) {
		if(find(i) == find(j)) return true;
		else return false;
	}

	void uni(int i, int j) {
		A[find(i)] = find(j);
	}

	void dfs(int ini, int maxi) {
		vis[ini] = 1;
		for(int i=0; i<(int)box[ini].size(); i++)
			if(vis[box[ini][i].first]==0){	
				int x = ini;
				while(p[x] != x) {
					x=p[x];
				}
				min_max[x][box[ini][i].first] = maxi = max(maxi,box[ini][i].second);
				p[box[ini][i].first] = x;
				dfs(box[ini][i].first, maxi);
			}	
	}
	void DFS() {
		for(int i=1; i<=C; i++) {
			vis.assign(C+1, 0);
			p.assign(C+1, -1);
			p[i] = i;
			dfs(i, 0);
		}
	}

	int main ()
	{
		int I=1;
		while(scanf("%d %d %d", &C, &S, &Q)) {
			if(C==0 && S==0 && Q==0)break; 
			if(I > 1)puts("");
		    printf("Case #%d\n", I);
			for(int i=0; i<S; i++) {
				scanf("%d %d %d", &ori, &dest, &w);
				edge.push_back(make_pair(w, pair<int,int>(ori,dest)));
			}
			sort(edge.begin(), edge.end());
			inicia();
			for(int i=0; i<S; i++) {
				if(!mesma(edge[i].second.first,edge[i].second.second)){
					uni(edge[i].second.first,edge[i].second.second);
					box[edge[i].second.first].push_back(make_pair(edge[i].second.second, edge[i].first));
					box[edge[i].second.second].push_back(make_pair(edge[i].second.first, edge[i].first));
				}	
			}
		    DFS();
			for(int i=0; i<Q; i++) {
				scanf("%d %d", &ori, &dest);
				if(min_max[ori][dest] != -1)printf("%d\n", min_max[ori][dest]);
				else printf("no path\n");
			}
			box.clear();
			edge.clear();
			min_max.clear();
			I++;
		}
	}
