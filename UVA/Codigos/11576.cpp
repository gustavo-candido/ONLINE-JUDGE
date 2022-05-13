#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010
string T, P;

int b[MAX_N], n, m, bit[MAX_N];

void completa() {
	//cout << "completa\n";
	
	for(int i = bit[n-1]; i < m; i++) {
		T.push_back(P[i]);
		//cout << P[i];
	}
	//puts("");
	//cout << T<< endl;
}

/*string reverse(string A) {
	P = A;
	char aux;
	int tam = P.size();
	for(int i=0; i<tam/2; i++) {
		aux = P[i];
		P[i] = P[tam-1-i]; 
		P[tam-1-i] = aux;
	}
	return P;
}*/
void kmpPreprocess() {
	int i = 0, j = -1; b[0] = -1;
	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	} 
}
void kmpSearch() {
	int i = 0, j = 0;

	while (i < n) {
		while (j >= 0 && T[i] != P[j]) j = b[j];
		bit[i] = j+1;
		i++; j++;
		if (j == m) {
			j = b[j];
		} 
	}
	/*for(int i=0; i<=m; i++) {
		cout << "i = "<< i << "bit[i] = "  << bit[i] << "\n";
	} */
	completa();
}

int main()
{
	int N, w;
	string aux;
	cin >> N;
	
	while(N--) {
		cin >> n >> w;
		w--;
		getchar();
		cin >> T;
		while(w--) {
			cin >> P;
			m = P.size();
			n = T.size();
			kmpPreprocess();
			kmpSearch();
		}
		cout << T.size() << endl;
	}
}

