#include <bits/stdc++.h>
#define INF 10000000
using namespace std;
//Q carai de asa é isso
vector< vector<double> >box, p;
int V;

void floyd_warshall() {
	for(int i=0; i<V; i++) 
		for(int j=0; j<V; j++) p[i][j]=i;
		
		
		
	for(int k=0; k<V; k++) {
		for(int i=0; i<V; i++) {
			for(int j=0; j<V; j++) {
				if(i!=j)box[i][j] = max(box[i][j], box[i][k]*box[k][j]);
			}
		}
	}
	
}

void print() {
	for(int k=0; k<V; k++) {
		for(int i=0; i<V; i++) {
			printf(" %.3lf", box[k][i]);
		}puts("");
	}
	puts("");
}

int main ()
{
	while(scanf("%d", &V) != EOF) {
		box.assign(100, vector<double>(100, INF));
		p.assign(100, vector<double>(100, INF));
		for(int i=0; i<V; i++) {
			for(int j=0; j<V; j++) {
				if(i==j)box[i][i] = 1.0;
				else scanf("%lf", &box[i][j]);
			}
		}
		floyd_warshall();
		print();
		box.clear();
		p.clear();
	}
}
