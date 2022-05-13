#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int N, Q, q, x, dif, C=1;
	vector<int> set;
	
	while (cin >> N) {
		if(!N)break;
		cout << "Case " << C << ":\n";
		C++;
		set.resize(N);
		for(int i=0; i<N; i++) {
			cin >> set[i];
		}
		sort(set.begin(), set.end());
		cin >> Q;
		for(int i=0; i<Q; i++) {
			cin >> q;
			dif = 2000000000;
			for(int j=0; j<N; j++) {
				for(int z=j+1; z<N; z++) {
					///cout << abs((set[j]+set[z]) - q) << "<----x\n";
					if(abs((set[j]+set[z]) - q) < dif) {
						dif =  abs((set[j]+set[z]) - q);
						x = (set[j]+set[z]);
					}
					if(!dif) {
						j = N;
						break;
					}
					if(abs(x - q) > dif) break;
				}
			}
			printf("Closest sum to %d is %d.\n", q, x);
		}
	}
}
