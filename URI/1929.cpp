#include <bits/stdc++.h>
using namespace std;

bool triangulo(int a, int b, int c) {
	return (a+b > c && a+c > b && b+c > a)? true:false;

}

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(triangulo(a,b,c) || triangulo(a,b,d) || triangulo(a,d,c) ||
	   triangulo(d,c,b)) cout << "S\n";
	else cout << "N\n"; 
}