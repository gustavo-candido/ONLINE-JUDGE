#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
	
typedef long long ll;

int n;
ll d, dist[102];
char type[102];

bool check(ll k) {
	vector<ll> v, u;
	bitset<105> vis;
	ll x;

	vis.reset();

	v.push_back(0);

	for(int i=0; i<n; i++)
		v.push_back(dist[i]);

	v.push_back(d);

	x = 0;


	while(x < d) {
		 auto val = lower_bound(v.rbegin(), v.rend(), x+k, greater<ll>());
		 int ind = lower_bound(v.begin(), v.end(), *val) - v.begin();

		if(x == *val) return false;
		x = *val;
	    vis[ind-1] = 1;
	}

	u.push_back(0);

	for(int i=n-1; i>=0; i--){
		if(vis[i] && type[i] == 'S') continue;
		u.push_back(d - dist[i]);
	}

	u.push_back(d);

	x = 0;

	while(x < d) {
		 auto val = lower_bound(u.rbegin(), u.rend(), x+k, greater<ll>());

		if(x == *val) return false;
		x = *val;
	}

	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, C=0;

	cin >> t;
	
	while(t--) {
		cin >> n >> d;
    	char cc;
  		for (int i = 0; i < n; ++i) {
    		cin >> type[i];
    		cin >> cc;
    		cin >> dist[i];
  		}


		ll l=1, r=d,  mid, ans;

		while(l<=r){
			mid = (l+r)/2;

			if(check(mid)){
				ans = mid;
				r = mid-1;
			}
			else {
				l = mid+1;
			}
		}

		cout << "Case " << ++C << ": " << ans << endl;
	}
}