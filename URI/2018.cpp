#include <bits/stdc++.h>
using namespace std;

typedef pair<string,int> ii;
typedef struct group{
	string a;
	int g, s, b;
	
	group(string _a){g = s = b = 0; a = _a;}
	group(string _a, int _g, int _s, int _b) {a = _a; g = _g; s = _s; b = _b;}
	
	bool operator < (group other) const{
		if(other.g != g) return g > other.g;
		if(other.s != s) return s > other.s;
		if(other.b != b) return b > other.b;
		return a < other.a;
	}
	
} group;

int main()
{
	string modalidade, a;
	vector<group> vet;
	map<string, int> pais;
	group aux = group(a);
	int g, s, b; 
	while(getline(cin, modalidade) && !cin.eof()) {
		getline(cin, a);
		if(!pais.count(a)) {
			pais.insert(ii(a, vet.size()));
			aux = group(a);
			aux.g++;
			vet.push_back(aux);
		}
		else vet[pais[a]].g++;
		getline(cin, a);
		if(!pais.count(a)) {
			pais.insert(ii(a, vet.size()));
			aux = group(a);
			aux.s++;
			vet.push_back(aux);
		}
		else vet[pais[a]].s++;
		getline(cin, a);
		if(!pais.count(a)) {
			pais.insert(ii(a, vet.size()));
			aux = group(a);
			aux.b++;
			vet.push_back(aux);
		}
		else vet[pais[a]].b++;
	}
	cout << "Quadro de Medalhas\n";
	sort(vet.begin(), vet.end());
	for(int i=0; i<vet.size(); i++) {
		cout << vet[i].a << " " << vet[i].g << " " << vet[i].s << " " << vet[i].b << endl;
	}


}