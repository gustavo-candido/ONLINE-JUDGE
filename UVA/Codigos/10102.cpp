#include <bits/stdc++.h>
#define dist(a,b,x,y) (abs(a-x) + abs(b-y))
using namespace std;



int main()
{
	int n, d, ans;
	char cell[1000][1000];
	vector< pair<int,int> > s;
	while(cin >> n && !cin.eof()) {
		getchar();
		s.clear();
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++){
			 	cin >> cell[i][j];
				if(cell[i][j] == '1')s.push_back(make_pair(i,j));
			}
		}
		
		ans = -10000000;
		for(int k=0; k<(int)s.size(); k++) {
			d = 10000000;
			int x = s[k].first, y = s[k].second;
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(cell[i][j] == '3') {
						d = min(d, dist(x,y,i,j)); 
					}
				}
			}
			ans = max(ans, d);
		}
		cout << ans << endl;
	}
}
