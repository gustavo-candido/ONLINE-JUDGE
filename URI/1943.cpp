#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	if(n == 1) puts("Top 1");
	else if(n <= 3) puts("Top 3");
	else if(n <= 5) puts("Top 5");
	else if(n <= 10) puts("Top 10");
	
	else if(n <= 25) puts("Top 25");
	else if(n <= 50) puts("Top 50");
	else if(n <= 100) puts("Top 100");
}