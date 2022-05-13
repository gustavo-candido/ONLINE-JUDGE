#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

vector< vector<int> >box, res;
vector<int> dist, p;
string path;
char dest[100], ori = '1', input[100];
int w, f, mf;

void augment(int v, int min_edge) {
	if(v == 0) {f = min_edge;return;} 
	else if(p[v] != -1) {
		augment(p[v], min(min_edge, res[p[v]][v]));
		 res[p[v]][v]-=f;
		 res[v][p[v]]+=f;
	}
}

int max_flow () {
	mf=0;
	path.assign(10, '_');
	while(1) {
		f=0;
		dist.assign(40, INF);
		dist[0] = 0;
		p.assign(40, -1);
		queue<int>q;
		q.push(0); 
		
		while(q.size()) {
			int u = q.front(); q.pop();
			
			if(u == 37) break;
			
			for(int i=0; i<38; i++) {
				if(res[u][i] > 0 && dist[i] == INF) {
					printf("%d ****\n", i);
					q.push(i);
					p[i] = u;
					dist[i] = dist[u]+1;
				}
			}
		}
		cout << path << endl;
		augment(37, INF);
		if(f==0)break;
		path[p[37]-27] = (char) p[p[37]]+64;
		mf+=f;
	}
	return mf;
}

void print() {
	for(int i=0; i<=37; i++) {
			for(int j=0;j<=37; j++) printf(" %d", res[i][j]);
		puts("");
	}
}
int main ()
{
	while(1) {
		if(gets(input) == 0)break;
		box.resize(40);
		res.assign(40, vector<int>(40,0));  
		for(int i=1; i<=26; i++) box[0].push_back(i);
		for(int i=27; i<=36; i++) {
			box[i].push_back(37);
			res[i][37] = 1;
		}
		sscanf(input, "%c%c %s", &ori, &w, dest);
		ori-='A'-1;
		w-='0';
		res[0][ori]+=w;
		for(int i=0; dest[i] != ';'; i++) {
			box[ori].push_back(27+dest[i]-'0');
			res[ori][27+dest[i]-'0'] = INF;
		}
		while(strcmp(gets(input), "") != 0) {
			sscanf(input, "%c%c %s", &ori, &w, dest);
			ori-='A'-1;
			w-='0';
			res[0][ori]=w;
			for(int i=0; dest[i] != ';'; i++) {
				box[ori].push_back(27+dest[i]-'0');
				res[ori][27+dest[i]-'0'] = INF;
			}
		}
		max_flow();
		printf("%d<---\n", mf);
		cout << path << endl;
		box.clear();
	}
}

