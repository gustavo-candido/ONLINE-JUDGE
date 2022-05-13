#include <bits/stdc++.h>
using namespace std;

int l, n, cut[100], mem[103][1030];
vector<int> d;
int min_cut(int left, int right){
	if(left+1 == right) return 0;
	int ans = 1000000;
	for(int i=left+1;i < right-1; i++) ans = min(ans, (min_cut(cut[left], cut[i])+min_cut(cut[i], cut[right])))+(cut[right] - cut[left]); 
	return ans;
}

int main()
{
	while(cin >> l && l != 0) {
		
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> cut[i];
		}
		memset(mem, -1, sizeof mem);	
		cout << min_cut(0, l) << endl;	
	}
	
}
