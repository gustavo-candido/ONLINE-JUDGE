#include<bits/stdc++.h>
using namespace std;

int main ()
{
	vector<int> vet, p, ase, asi;
	stack<int> pilha;
	int index;
	
	while(scanf("%d", &index) != EOF) {
		vet.push_back(index);
	}
	p.resize(vet.size());
	
	p[0] = -1;
	asi.push_back(0);
	ase.push_back(vet[0]);
	
	for(int i=1; i<vet.size(); i++) {
		index = lower_bound(ase.begin(), ase.end(), vet[i]) - ase.begin();
		
		if(index == ase.size()) {
			p[i] = asi[asi.size()-1];
			asi.push_back(i);
			ase.push_back(vet[i]);
		}
		else {
			if(index == 0) {
				p[i] = -1;
			}
			
			else {
				p[i] = asi[index-1];
			}
			asi[index] = i;
			ase[index] = vet[i];
		}
	}
	
	printf("%d\n-\n", ase.size());
	index = asi[asi.size()-1];
	while(index != -1) {
		pilha.push(vet[index]);
		index = p[index];
	}
	while(pilha.size()) {
		printf("%d\n", pilha.top());
		pilha.pop();
	}
 }
