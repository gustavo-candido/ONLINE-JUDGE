#include <bits/stdc++.h>
#define INF 10000000
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> grf;
vi st;

int V, f, maxi, ind, mini;


int sssp(int s) {
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    vi dis(V+1, INF);
    int u, d;
    ii v;
    for(int i=0; i<(int)st.size(); i++) {
        pq.push(ii(0,st[i]));
        dis[st[i]] = 0;
    }
    pq.push(ii(0,s));
    dis[s]=0;
    while(pq.size()) {
        v = pq.top(); pq.pop();
        u = v.second; d = v.first;
        if(d > dis[u]) continue;
        for(int i=0; i<(int)grf[u].size(); i++) {
            v = grf[u][i];
            if(d+v.second < dis[v.first]) {
                dis[v.first] = d+v.second;
                pq.push(ii(dis[v.first], v.first));
            }
        }
    }
    int i=1;
    for(int j=2; j<=V; j++)
        if(dis[j] > dis[i]) i=j;
    return dis[i];
}
int sssp_call()
{
    int d;
    mini = INF;
    ind = 1;
    if(st[0] == 1) mini= sssp(1);

    for(int j=1; j<=V; j++)
        if(!binary_search(st.begin(), st.end(), j)){
            d = sssp(j);
            if(d < mini){ind=j;mini=d;}
        }
    return ind;
}
int main()
{
	int T, o, d, dist;
	char *aux, line[100];
	scanf("%d", &T);

	for(int C=0; C<T; C++){
		if(C) cout << endl;
		scanf("%d %d", &f, &V);

		st.clear();
		grf.clear();
		grf.resize(V+1);
		for(int i=0; i<f; i++) {
			scanf("%d", &o);
			st.push_back(o);
		}sort(st.begin(), st.end());getchar();

		while(gets(line) != NULL){
            if(strcmp(line, "") == 0) break;
            aux = strtok(line, " ");
            o = atoi(aux);
            aux = strtok(NULL, " ");
            d = atoi(aux);
            aux = strtok(NULL, " ");
            dist = atoi(aux);
            grf[o].push_back(ii(d,dist));
            grf[d].push_back(ii(o,dist));
		}
		cout << sssp_call() << endl;
	}
}
