#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

vector< vector<int> > box;
int ori, dest, maxi, c, x, C=1;
set<int>s;
long long int Floyd(){
	for(int k=1; k<=maxi; k++) {
		for(int i=1; i<=maxi; i++) {
			for(int j=1; j<=maxi; j++) {
				if(i==j) box[i][j] = 0;
				else box[i][j] = min(box[i][j], box[i][k] + box[k][j]);
			}
		}
	}
	return 0;
}
void print () {
	for(int i=1; i<=maxi; i++) {
		for(int j=1; j<=maxi; j++) {
			if(box[i][j] != INF){
				c+=box[i][j];
				x++;
				//printf(" %.9d", box[i][j]);
			}//puts("");
		}
	//printf("%d\n", c);
	}
}
int main()
{
	while(scanf("%d %d", &ori, &dest), (ori && dest)) {
		box.assign(200, vector<int>(200, INF));
		maxi=-1*INF;
		box[ori][dest] = 1;
		maxi = max(maxi, max(ori,dest));
		c = 0;
		s.insert(ori);
		s.insert(dest);
		while(scanf("%d %d", &ori, &dest), (ori && dest)) {
			box[ori][dest] = 1;
			maxi = max(maxi, max(ori,dest));
			s.insert(ori);
			s.insert(dest);
		}
		Floyd();
		print();
		printf("Case %d: average length between pages = %.3lf clicks\n", C,(double)c/(s.size() * (s.size()-1)));
		box.clear();
		s.clear();
		C++;
	}
}
