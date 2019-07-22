#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, b, x, y;

	scanf("%d %d %d %d %d", &n, &a, &b, &x, &y);

	if(n >= a && n <= b &&  n >= x && n <= y) puts("possivel");
	else puts("impossivel");
}