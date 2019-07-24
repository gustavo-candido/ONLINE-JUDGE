#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int B = 400;

int n, q, v[N];

int ini[B], fim[B], freq[B][N];

int bloc_id(int pos) {
	return (pos - pos%B)/B;
}

void update(int pos, int val) { 
	int idx = bloc_id(pos);

	freq[idx][v[pos]]--;
	freq[idx][val]++;
	v[pos] = val;
}

int query(int l, int r, int val) {
	int ans = 0;
	int a = bloc_id(l);
	int b = bloc_id(r);

	if(a == b) {
		for(int i=l; i<=r; i++)
			if(v[i] != val) ans++;
		return ans;
	}

	a = ini[a+1];
	b = fim[b-1];

	for(; l<a; l++)
		if(v[l] != val) ans++;

	for(; r>b; r--) 
		if(v[r] != val) ans++;

	a = bloc_id(a);
	b = bloc_id(b);

	while(a<=b) {
		ans+=fim[a]-ini[a]+1-freq[a][val];
		a++;
	}

	return ans;
}


int main()
{
	scanf("%d %d", &n, &q);

	for(int i=0, sz=0; i<n;  i+=B, sz++) {
		ini[sz] = i;
		fim[sz] = min(i+B-1, n);
	}

	for(int i=0; i<n; i++) {
		scanf("%d", &v[i]);
		freq[bloc_id(i)][v[i]]++;
	}

	int op, l, r, val;

	while(q--) {
		scanf("%d %d %d", &op, &l, &r);

		if(op == 1) 
			update(--l, r);
		else {
			scanf("%d", &val);
			printf("%d\n",query(--l, --r, val));
		}
	}
}