#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int sum, n, x, X, A, tam, TAM, count;
	vector<int> set;
	
	while(scanf("%d", &sum) != EOF) {
		cin >> n;
		set.resize(n);
		X= -2000000000;
		TAM = 0;
		for(int i=0; i<n; i++) cin >> set[i];
		
		for(int i=0; i < (1 << n); i++) {
			x=0;
			count=0;
			for(int j=0; j<n; j++) {
				if(i & (1 << j)) {x+=set[j];count++;}
			}
			tam = count;
			if(x <= sum && x > X){
				X = x;
				TAM = tam;
				A = i;
			}
			else if(x <= sum && x == X) {
				if(tam > TAM) {TAM = tam; A=i;}
			}
		}
		for(int i=0; i<n; i++) {
			if(A & (1 << i)) printf("%d ", set[i]);
		}
		printf("sum:%d\n", X);
	}
}
