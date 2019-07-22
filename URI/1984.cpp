#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a;
	char aux;	
	cin >> a;
	for(int i=0; i<(a.size()/2); i++) {
		aux = a[i];
		a[i] = a[(a.size()-1)-i];
		a[(a.size()-1)-i] = aux;
	}
	cout << a << endl;
}