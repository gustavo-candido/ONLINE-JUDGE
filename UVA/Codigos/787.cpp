#include <bits/stdc++.h>

using namespace std;

int main ()
{
	double MAX = -999999, max=1, vet[1000];int size=1;
	while(scanf("%lf", &vet[0]) != EOF) {
		size = 1;
		MAX = -999999;
		while(scanf("%lf", &vet[size]), vet[size] != -999999) {
			size++;
		}
		
		for(int i=0; i<size; i++) {
			max = 1;
			for(int j=i; j<size; j++) {
				max*=vet[j];
				if(MAX < max) MAX = max;
				if(max == 0) max = 1; 
			}
		}
		printf("%0.lf\n", MAX);
	}
}
