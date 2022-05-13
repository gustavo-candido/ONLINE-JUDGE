#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

vector< vector<int> >box;
int V, A, maxi, C;
string ori, dest;
map<string, int>m;


void Floyd_Warsahll(){
	for(int k=0; k<V; k++) {
		for(int i=0; i<V; i++) {
			for(int j=0; j<V; j++) {
				box[i][j] = min(box[i][j], box[i][k]+box[k][j]);
			}
		}
	}
}

int main ()
{
	C=1;
	while(scanf("%d %d", &V, &A) && (V && A)) {
		box.assign(100, vector<int>(100, INF));
		maxi = -1 * INF;
		getchar();
		for(int i=0; i<A; i++) {
			cin >> ori >> dest;
			if(!m.count(ori)) m.insert(make_pair(ori, m.size()));
			if(!m.count(dest)) m.insert(make_pair(dest, m.size()));
			box[m[ori]][m[dest]] = 1;
			box[m[dest]][m[ori]] = 1;
		}
		for(int i=0; i<V; i++) box[i][i] = 0; 
		Floyd_Warsahll();
		
		for(int i=0; i<V; i++) {
			for(int j=0; j<V; j++) {
				maxi = max(maxi, box[i][j]);
			}
		}
		printf("Network %d: ", C);
		if(maxi == INF) printf("DISCONNECTED\n\n"); 
		else printf("%d\n\n", maxi);
		C++;
		m.clear();
		box.clear();
	}
}

