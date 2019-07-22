#include <bits/stdc++.h>
using namespace std;

int main()
{
	double n, mini, maxi;

	cin >> n;
	mini = n/log(n);
	maxi = 1.25506 * mini;

	printf("%.1lf %.1lf\n", mini, maxi);
}