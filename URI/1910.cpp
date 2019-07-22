#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int o, d, k, aux;
bool s[100001];

int op(int id, int i) {
	if(id == 0) return i-1;
	if(id == 1) return i+1;
	if(id == 2) return i*2;
	if(id == 3) return i*3;
	if(id == 4) return (i%2 == 0)? i/2:110000;	
	return -1;
}
bool valid(int i) {
 return !(i < 0 || i > 100000 || s[i]);
}

void bfs()
{
	queue<ii> q;
	q.push(ii(o,0));
	bool f=false;
	
	while(q.size()) {
		ii v = q.front(); q.pop();
		if(v.first == d){cout << v.second << endl;f=true;break;}
		for(int i=0; i<5; i++) {
			aux = op(i, v.first);
			if(valid(aux)) {q.push(ii(aux,v.second+1));s[aux] = true;}
		}
	}
	if(!f) puts("-1");
}


int main()
{
	while(cin >> o >> d >> k)  {
		if(o == 0 && d == 0 && k == 0) break;
		memset(s, false, sizeof s);
		for(int i=0; i < k; i++) {
			cin >> aux;
			s[aux] = true;
		}
		bfs();
	}
}