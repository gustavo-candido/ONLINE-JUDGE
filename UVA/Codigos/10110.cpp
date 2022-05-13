#include <bits/stdc++.h>
using namespace std;

int main() 
{
	long long int x, n;
	
	while(scanf("%lld", &x) && x) {
		n = sqrt(x);
		if(n*n == x)printf("yes\n");
		else printf("no\n");
	
	}
}
