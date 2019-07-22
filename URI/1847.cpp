#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if(a > b && b <= c) cout << ":)\n";
	else if(a < b && b >= c) cout << ":(\n";
	else if(a < b && b < c && abs(c-b) < abs(a-b)) cout << ":(\n";
	else if(a < b && b < c && abs(c-b) >= abs(a-b)) cout << ":)\n";
	else if(a > b && b > c && abs(b-c) <  abs(a-b)) cout << ":)\n";
	else if(a > b && b > c && abs(b-c) >=  abs(a-b)) cout << ":(\n";
	else if(a == b && b < c) cout << ":)\n";
	else cout << ":(\n";
}