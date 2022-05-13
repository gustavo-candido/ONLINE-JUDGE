#include <bits/stdc++.h>
using namespace std;

int x;

int priori (string a) {
	if(a.compare("+") == 0 || a.compare("-") == 0) return 1;
	else if(a.compare("*") == 0 || a.compare("/") == 0) return 2;
	else if(a.compare("^") == 0) return 3;
	else if(a.compare("(") == 0 || a.compare(")") == 0) return 4;	
	else return -1;
}
bool is_num(string A) {
	for(int i=0; i<(int)A.size(); i++) if(A[i] < 48 || A[i] > 57)return false;
	return true;
}

string op (string a, string b, string op) {
	int x, y, z;
	string result;
	char aux[100];

	x = atoi(a.c_str());
	y = atoi(b.c_str());
	printf("resolvendo alguma operação com %d e %d\n", x, y);
	if(op.compare("+") == 0) z = x+y;
	else if(op.compare("-") == 0) z = x-y;
	else if(op.compare("*") == 0) z = x*y;
	else if(op.compare("/") == 0) z = x/y;
	else if(op.compare("^") == 0) z = pow(x,y);
	sprintf(aux, "%d", z);
	return result = aux;
}

string resolve(string A) {
	stack<string> pilha, ope;
	string aux, a, b, c;
	cout << "expressao: " << A << endl;
	for(int i=0; i<(int)A.size(); i++) {
		aux.clear();
		if(A[i] >= 48 && A[i] <= 57){
			while(A[i] >= 48 && A[i] <= 57) {
				aux.push_back(A[i]);
				i++;
			}
			i--;
		}
		else if(!priori(aux)) return "ERROR";
		else aux = A[i];
		//cout << "aux = '" <<  aux << "'" << endl;
		if(ope.empty() || is_num(aux) == true || priori(aux) >= priori(ope.top())) {
		//	puts("pilha push aux");
			pilha.push(aux);
			if(priori(aux) > 0){/*puts("ope push aux");*/ope.push(aux);}
		}
		else if(aux.compare(")") == 0) {
			a.clear();
	//		puts("resolve parenteses");
			while(pilha.top() != "(") {
				a+=pilha.top();
				if(pilha.top() == ope.top()) {/*cout << "ope pop '" << ope.top() << "'\n";*/ope.pop();}
		//		cout << "pilha pop '" << pilha.top() << "'\n";pilha.pop();
			}
			//cout << "pilha pop '" << pilha.top() << "'\n";
			pilha.pop();
			//cout << "expressao parentesis '" << a << "'\n";
			if(pilha.top() == ope.top()) {/*cout << "ope pop '" << ope.top() << "'\n";*/ope.pop();}
			pilha.push(resolve(a));
		//	cout << "expressao resolvida '" << pilha.top() << "'\n";
		}
	}
	
	while(ope.size()) {
		//puts("q");
		a = pilha.top();/*cout << "pilha pop '" << pilha.top() << "'\n";*/ pilha.pop();	
		b = pilha.top();/*cout << "pilha pop '" << pilha.top() << "'\n";*/ pilha.pop();
		c = pilha.top();/*cout << "pilha pop '" << pilha.top() << "'\n";*/ pilha.pop();
		//cout << "pop ope " << ope.top() << "    ope size " << ope.size()-1 << endl;  
		ope.pop();
		if(!is_num(a) || !priori(b) || !is_num(c)) return "ERROR";
		pilha.push(op(c,a,b));
		cout << "Expressao resolvida '" << pilha.top() << "'\n"; 
		//puts("pilha push "); cout << aux << endl;
		//pilha.push(aux);
	}		
	if(pilha.size() == 1) return pilha.top();
	else return "ERROR";
}

int main()
{
	int T;
	string express;
	
	scanf("%d", &T);getchar();
	
	while(T--) {
		cin >> express;
		cout << "result:"<< resolve(express) << endl;
	}
}
