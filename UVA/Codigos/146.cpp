#include <bits/stdc++.h>

using namespace std;

main ()
{
	string str, aux;
	int tam;
	while(getline(cin, str), str != "#") {
		aux = str;
		next_permutation(str.begin(), str.end());
		sort(aux.begin(), aux.end());
		if(aux != str)cout << str << endl;
		else cout << "No Successor\n";
	}
}
