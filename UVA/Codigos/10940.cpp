#include <bits/stdc++.h>

using namespace std;

vector<int> pares;

int main(){
	int N;
	for(int i=2; i<=600000; i+=2) pares.push_back(i);
	while(cin >> N, N){
		if(N == 1) {cout << 1 << endl; continue;}
		int k = -1;
		for(int i=0; i<=20; i++){
			if(N & (1<<i)){
				k = i;
			}
		}
		//printf("k = %d\n", k);
		int dif = abs((int)pow(2, k) - N);
		printf("%d\n", pares[dif-1]);
	}
}
