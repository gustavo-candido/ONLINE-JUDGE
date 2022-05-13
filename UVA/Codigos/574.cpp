#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int N,  n, x;
	vector<int> vet, aux;
	set < vector< int > > sum;
	
	while(cin >> N >> n, N, n) {
		vet.resize(n);
		for(int i=0; i<n; i++) cin >> vet[i];
		
		for(int i=0; i < (1 << n); i++) {
			x=0;
			aux.clear();
			for(int j=0; j<n; j++) {
				if (i & (1 << j)) {
					x+=vet[j];
					aux.push_back(vet[j]);
				}
			}
			if(x == N) sum.insert(aux);
		}
		printf("Sums of %d:\n", N);
		if(sum.size()) {
			for(set< vector<int> >:: reverse_iterator i = sum.rbegin(); i != sum.rend(); i++){ 
				for (int j=0; j<(*i).size()-1; j++) {
					cout << (*i)[j] << "+";
				}
				cout << (*i)[(*i).size()-1] << "\n";
			}
			sum.clear();
		}
		else cout << "NONE\n";
		sum.clear();
	}
}
