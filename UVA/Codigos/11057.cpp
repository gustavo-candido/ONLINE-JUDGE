#include <bits/stdc++.h>
using namespace std;
	
	int N, sum, x, y, aux;
	vector<int> vet;
	
int busca (vector<int>A, int B, int N) {
    int de=0, ate=N-1, x=-1, meio;
    while (de<=ate && x==-1) {
        meio = de + ((ate-de)/2);
        if (A[meio]<B) {
            de = meio+1;
        }
        else if (A[meio]>B) {
            ate = meio-1;
        }
        else x=meio;
    }
    
    int i = x+1;
    while(A[i]==A[x]) {
		x++;
		i++;
	}
     return x;
}

void scan () {
	vet.resize(N);
	for(int i=0; i<N; i++) {
		cin >> vet[i];
	}
	cin >> sum;
}		

void process () {
	int tam = vet.size();
	sort(vet.begin(), vet.end());
	for (int i=0; i < tam && vet[i] <= (sum/2); i++) {
		aux = busca(vet, sum-vet[i], vet.size());
		if (aux != -1 && i != aux) {
			x = i;
			y = aux;
		}
	}
	printf("Peter should buy books whose prices are %d and %d.\n\n", vet[x], vet[y]);
}

int main ()
{
	while(scanf("%d", &N) != EOF) {
		scan();
		process();
	}
}
