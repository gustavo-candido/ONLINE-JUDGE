#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tam, maxi= 0, cont, K=0, pos;
	bool new_line=true;
	string alf= " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string A,B,aux;
	set<string> s;
	
	while(cin >> aux && aux.compare("#") != 0) {
		s.insert(aux);
	}
	
	getchar();
	getline(cin, A);
	tam = A.size();
	
	for(int k=0; k < 27; k++) {
		B.clear();
		for(int i=0; i<tam; i++) {
			pos = (alf.find(A[i]) + k) % 27;
			B+=alf[pos];
		}
		cont=0;
		for(char *p = strtok((char*)B.c_str(), " ");p; p = strtok(NULL, " ")) {
			if(s.count(p)) cont++;
		}
		if(cont > maxi) {K=k;maxi = cont;}
	}
	
	for(int i=0; i<tam; i++) B[i] = alf[(alf.find(A[i]) + K) % 27];
	cont=0;
	
	for(char *p = strtok((char*)B.c_str(), " ");p; p = strtok(NULL, " ")) {
		if(cont+strlen(p) > 60) {puts("");cont=0;new_line=true;}
		if(new_line){printf("%s", p);new_line=false;}
		else {printf(" %s", p);cont++;}
		cont+=strlen(p);
	}puts("");
}
