#include <bits/stdc++.h>

using namespace std;

int value (vector<string> pilha) {
		string a;
		a=pilha.back();
		return ((int)a[0]-48 < 10) ? (int)a[0]-48 : 10;
}
int main ()
{
	int N, y, x;
	vector<string> pilha;
	char aux[5];

	scanf("%d", &N);
	getchar();
	for(int c=1; c<=N; c++) {
		for(int i=0; i<27; i++) {
			scanf("%s", aux);
			pilha.push_back(aux);
		}
		y=0;
		
		for(int i=0; i<3; i++) {
			x = value(pilha);
			y+=x;
			pilha.pop_back();
			for(int i=0; i<10-x;i++) pilha.pop_back();
		}
		for(int i=0; i<25; i++) {
			scanf("%s", aux);
			pilha.push_back(aux);
		}
		cout << "Case " << c << ": "<< pilha[y-1] << endl;
		pilha.clear();
	}
}
