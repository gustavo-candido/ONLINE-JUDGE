#include <bits/stdc++.h>
using namespace std;

vector< vector<int> >box;
vector<int> grau, vis, ans;
map<string, int> dic;
map<int, string> rdic;
int V, A;
priority_queue<int, vector<int>, greater<int> > fila;
char drink[10000];

void bfs () {
	int topo;
	for(int i=0; i<V; i++) {
		if(grau[i] == 0) {
			fila.push(i);
			//cout << "push " << rdic[i] << endl;
			//vis[i] = 1;
		}
	}
	while(fila.size()) {
		topo = fila.top();
		ans.push_back(topo);
		//cout << "pop " << rdic[fila.top()] << endl;
		fila.pop();
		for(int i=0; i < box[topo].size(); i++) {
			grau[box[topo][i]]--;
			//cout << rdic[box[topo][i]] << " grau " << grau[box[topo][i]] << endl;
			if(grau[box[topo][i]] == 0){fila.push(box[topo][i]);}//vis[box[topo][i]]=1;}//cout << "push " << rdic[box[topo][i]] << endl;}
		}
	}
}

void BFS() {
	for(int i=0; i<V; i++) {
		if(grau[i]==0 && vis[i]== -1) bfs();
	}
}
int main ()
{
	char ori[10000], dest[10000];
	int C=1;
	while(scanf("%d", &V)!= EOF) {
		getchar();
		box.resize(V);
		vis.assign(V, -1);
		grau.assign(V, 0);
		for(int i=0; i<V; i++) {
			gets(drink);
			dic.insert(pair<string, int> (drink, i));
			rdic.insert(pair<int, string> (i, drink));
		}
		scanf("%d", &A);
		getchar();
		for(int i=0; i<A; i++) {
			scanf("%s", ori);
			scanf("%s", dest);
			box[dic[ori]].push_back(dic[dest]);
			grau[dic[dest]]++;
		}
		bfs();
		printf("Case #%d: Dilbert should drink beverages in this order:", C);
		for(int i=0; i<ans.size(); i++) {
			cout <<" " << rdic[ans[i]];
		}puts(".");puts("");
		C++;
		ans.clear();
		box.clear();
		rdic.clear();
		dic.clear();
	}
}
