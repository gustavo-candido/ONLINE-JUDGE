#include <bits/stdc++.h>
using namespace std;

int main()
{
	double raiz = sqrt(5.0), n;

	cin >> n;

	printf("%.1lf\n", (pow((1.0+raiz)/2.0, n) -  pow((1.0-raiz)/2.0, n)) / raiz);  

	
}