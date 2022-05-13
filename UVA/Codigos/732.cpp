#include <bits/stdc++.h>
using namespace std;

string a, b;
set<string> ans;

void f(string pilha, string tent, string inst, int id) {
	if(tent.size() && tent[tent.size()-1] != b[tent.size()-1]) return;
	if(id > b.size() || tent.size() > b.size() || pilha.size() > b.size()) return;
	if(pilha.size() == b.size()) {
		while(pilha.size()) {
			tent.push_back(pilha[pilha.size()-1]);
			inst.push_back('o');
			pilha.erase(pilha.end()-1);
		}
		if(tent != b) return;
	}

	if(tent == b) {ans.insert(inst);return;}
	
	pilha.push_back(a[id]);
	inst.push_back('i');
	f(pilha, tent, inst, id+1);
	pilha.erase(pilha.size()-1);
	inst.erase(inst.size()-1);

	if(pilha.size()){
		tent.push_back(pilha[pilha.size()-1]);
		pilha.erase(pilha.size()-1);
		inst.push_back('o');
		f(pilha, tent, inst, id);
	}
}

int main()
{
	while(getline(cin, a) && !cin.eof()) {
		if(a.size() == 0) {
			while(a.size() == 0 && !cin.eof()) getline(cin, a);
		}
		if(cin.eof()) return 0;
		getline(cin, b);
		if(b.size() == 0) {
			while(b.size() == 0 && !cin.eof()) getline(cin, b);
		}
		string pilha, tent, inst;
		ans.clear();
		f(pilha, tent, inst, 0);
		puts("[");
		for(set<string>::iterator i = ans.begin(); i != ans.end(); i++) {
			string aux = *i;
			printf("%c", aux[0]);
			for(int i=1; i < aux.size(); i++) {	
				printf(" %c", aux[i]);
			}puts("");
		}
		puts("]");
	}
}
