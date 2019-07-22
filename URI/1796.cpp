#include <bits/stdc++.h>
#define _n 233005
using namespace std;

int main()
{
	int n, v=0, aux;

	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		scanf("%d",&aux);
		if(!aux)v++;
	}
	if(v > n/2) puts("Y");
	else puts("N");
}