#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;


typedef pair<int,int> ii;

int box[8][8], place, tot;

int f(int x, int y, int k, vector<ii>bis, int u) {
	if(x >= tot) return 0;
	if(y >= tot) return f(x+1, 0, k, bis, u);
	if(k == place) return 1;
	if(box[x][y] != u) return f(x, y+1, k, bis, u);
	int ans = 0;
	
	bool ok = true;
	for(int v = 0; v < (int)bis.size(); v++) {
		if( abs(bis[v].F - x) == abs(bis[v].S - y)){ok = 0; break;}
	}
	if(ok) {
		bis.push_back(ii(x, y));
		ans+=f(x, y, k+1, bis, u);
		bis.pop_back();
	}
	ans+=f(x, y+1, k, bis, u);
	return ans;
}
int main()
{
	int b[9][65], p[9][65], ans[9][65];
	memset(box, 0, sizeof box);
	memset(b, 0, sizeof b);
	memset(p, 0, sizeof p);
	memset(ans, 0, sizeof ans);
	int aux=0;

	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			box[i][j] = aux;
			aux = 1 - aux;
		}
		aux = 1 - aux;
	}

	for(int i=1; i<=8; i++) {
		tot = i;
		for(int j=1; j<10; j++) {
			place = j;
			b[i][j] =  f(0, 0, 0, vector<ii>(), 0);
		}
	}
	for(int i=1; i<=8; i++) {
		tot = i;
		for(int j=1; j<10; j++) {
			place = j;
			p[i][j] =  f(0, 0, 0, vector<ii>(), 1);
		}
	}

	for(int i=1; i<9; i++) {
		for(int j=1; j<65; j++) {
			if((i-1)*2 < j) break;
			ans[i][j]+=b[i][j];
			ans[i][j]+=p[i][j];
			for(int k = 1; k<66; k++) {
				for(int l = 1; l<66; l++) {
					if(k+l == j) ans[i][j]+=(b[i][k]*p[i][l]);
				}
			}
		}
	}
	while(scanf("%d %d", &tot, &place) && tot+place) {
		 if(place == 0 || (tot == 1 && (place == 0 || place == 1))) puts("1");
		 else printf("%d\n", ans[tot][place]);
	}
}
