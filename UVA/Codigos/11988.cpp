#include <bits/stdc++.h>
using namespace std;

/// Teclado quebrado
void insere (string &A, list<string> &l, bool &x) {
	if(x) l.push_back(A);
	else  l.push_front(A);
	A.clear();
	x = true;
} 
int main ()
{
	list<string> l;
	list<string>::iterator it;
	string str;
	char aux;
	bool X = true;
	while(scanf("%c", &aux) != EOF) { 
		if(aux == '\n') {
			insere(str, l, X);
			for(it = l.begin(); it!= l.end(); it++) {
				cout << *it;
			}
			cout << endl;
			l.clear();
			X = true;
		}
		else if(aux == '[') {
			insere(str, l, X);
			X = false;
		}
		else if(aux == ']') {
			insere(str, l, X);
			X = true;
		}
		else str.push_back(aux);
	}
}
