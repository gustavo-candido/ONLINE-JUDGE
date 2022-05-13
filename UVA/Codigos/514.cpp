#include <bits/stdc++.h>
using namespace std;
//trilhos
void print (vector<int> saida, int count) {
	cout << "||";
	for(int i = count; i<saida.size(); i++) {
		cout << " " << saida[i];
	}
	cout << endl;
}

int main ()
{
	int N, n, aux, count;
	vector<int>saida, entrada;
	stack<int>estacao;
	comeco:
	while(cin >> N) {
		if(!N)break;
		n = N;
		while(1){
			count=0;
			for(int i=0; i<n; i++) {
				cin >> aux;
				if(!aux) {cout << endl; goto comeco;}
				saida.push_back(aux);
			}
			for(int i=1; i<=n; i++) {
				estacao.push(i);
			//	cout << "push " << i;
			//	print(saida,count);
				while(estacao.size() != 0) {
				//	cout << estacao.top() << "    "  << saida[count] << endl;
					if(estacao.top() != saida[count]) break;
				//	cout << "pop " << estacao.top();
					//print(saida, count);
					estacao.pop();
					count++;
				}
			}
			if(!estacao.size() && count==n) cout << "Yes\n";
			else cout << "No\n";
			while(!estacao.empty()) estacao.pop();
			saida.clear();
		}
	}
}
