#include <bits/stdc++.h>
#define inf 100000009
using namespace std;

const int N = 1030;

typedef struct iiii {
	int id, l, r, val;

	iiii() {
		id = l = r = val = 0;
	}

	iiii(int a, int b, int c, int d) {
		id = a;
		l = b;
		r = c;
		val = d;
	}

	bool operator < (iiii other) const {
		if(l != other.l) return l < other.l; 
		if(r != other.r) return r < other.r;
		return id < other.id; 
	}
} iiii;

int n, m, dp[N][N];
vector<iiii> v;

int bs(int k) { 
	int l=0, r=m-1, mid,ans=inf;

	while(l<=r) {
		mid = (l+r)/2;

		if(v[mid].l >= k) ans = mid;

		if(v[mid].l >= k) r = mid-1;
		else l = mid+1;
	}

	return ans;
}

int go(int bit, int i) {
	if(bit == (1<<n)-1 && i >= m) return 0;
	if(i >= m) return -inf;
	if(~dp[bit][i]) return dp[bit][i];

	int j = bs(v[i].r);

	return dp[bit][i] = max(go(bit, i+1), go(bit|v[i].id, j)+v[i].val);
}

int main()
{
	scanf("%d", &n);


	for(int i=0; i<n; i++) {
		int x;

		scanf("%d", &x);

		for(int j=0; j<x; j++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			v.push_back(iiii((1<<i),a,b,c));
		}
	}

	sort(v.begin(), v.end());
	memset(dp, -1, sizeof dp);

	m = v.size();

	int ans = go(0,0);

	if(ans<0) ans = -1;
	
	printf("%d\n", ans);
}


