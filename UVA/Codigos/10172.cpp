#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int N, S, Q, set, Qi, aux, pac, time;
	queue<int> pais[102];
	stack<int> pilha;
	
	cin >> set;
	
	while (set--) {
		cin >> N >> S >> Q;
		pac = 0;
		for(int i=1; i<=N; i++) {
			cin >> Qi;
			pac+=Qi;
			for(int j=1; j<=Qi; j++) {
				cin >> aux;
				pais[i].push(aux);
			}
 		}
 		time = 0;
 		aux = 1;
 		while(1) {
			while(!pilha.empty()) {
				if (pilha.top() == aux) {
					pilha.pop();
					pac--;
				}
				else {
					if(pais[aux].size() < Q) {
						pais[aux].push(pilha.top());
						pilha.pop();
					}
					else break;
				}
				time++;
			}
			if(pac == 0) break;
			while(pilha.size() < S && !pais[aux].empty()) {
				pilha.push(pais[aux].front());
				pais[aux].pop();
				time++;
			}
			aux++;
			time+=2;
			if(aux > N) aux = 1;
		}
		cout << time << endl;
	}
}
