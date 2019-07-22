#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int n;
ii points[1005];

int main()
{
	while(scanf("%d",  &n) != EOF){
		for(int i=0; i<n; i++) {
			scanf("%d %d", &points[i].first, &points[i].second);
		}

		int ans=0;

		sort(points, points+n);

		for(int i=0; i<n; i++) {
			int aux=1, a=points[i].second-1, x=-1, last=points[i].first;
			int aux2=1, b=points[i].second+1, y=1, last2=points[i].first;

			for(int j=i+1; j<n; j++) {
				if(points[j].second == a+x && last != points[j].first) {
					aux++;
					x*=-1;
					last = points[j].first;
				}
				if(points[j].second == b+y && last2 != points[j].first) {
					aux2++;
					y*=-1;
					last2 = points[j].first;
				}
			}
			ans = max(ans, aux);
			ans = max(ans, aux2);
		}

		printf("%d\n", ans);
	}
}