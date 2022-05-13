#include <bits/stdc++.h>
using namespace std;


bool pilha(int num, list< int > sacola) {
	//cout << "pilha " << sacola.back()  << endl;
	if(sacola.back() == num || sacola.back() == 1000){return true;}
	else return false;
}

bool fila(int num, list< int > sacola) {
	cout << "fila " << sacola.front()  << endl;
	if(sacola.front() == num || sacola.front() == 1000) {cout << "ok\n";return true;}
	else return false;
}

bool fila_prior (int num, priority_queue <int> &sacola) {
	//cout << "fila prio " << sacola.top()  << endl;
	if(sacola.top() == num) {
		sacola.pop();
		return true;
	}
	else return false;
}
bool find(list<int> sacola, int num) {
	bool x = true;
	 for (std::list<int>::reverse_iterator it=sacola.rbegin(); it != sacola.rend(); ++it){
		if(*it == num) return x;
	}
	return false;
}
void r_stack(list<int> &sacola, int num) {
	 for (std::list<int>::reverse_iterator it=sacola.rbegin(); it != sacola.rend(); ++it){
		if(*it == num) {*it = 1000;break;}
	}
}
void r_queue(list<int> &sacola, int num) {
	 for (std::list<int>::iterator it=sacola.begin(); it != sacola.end(); ++it){
		if(*it == num) {*it = 1000; break;}
	}
}

void print(list<int> sacola) {
	 for (std::list<int>::iterator it=sacola.begin(); it != sacola.end(); ++it){
		 cout << " "<< *it ;
	}cout << endl;
}

int main ()
{
	priority_queue <int> aux;
	list<int> sacola;
	int N, op, num;
	bool f, fp, p;
	while(scanf("%d", &N) != EOF) {
		f = fp = p = true;
		while(N--) {
			cin >> op >> num;
			if(op == 1) {
				sacola.push_back(num);
				aux.push(num);
			 //print(sacola);
			} 
			else if(op == 2) {
				if(find(sacola, num)){
					if(p)p = pilha(num, sacola);
					if(f)f = fila(num, sacola);
					if(!f && p) r_stack(sacola, num);
					else r_queue(sacola, num);
					if(fp)fp = fila_prior(num, aux);
					sacola.remove(1000);
				//print(sacola);
				}
				else p = f = fp = false;
			}	
		}
		num = 0;
		if(p) num++;
		if(f) num++;
		if(fp) num++;
		if(num == 0) cout << "impossible\n";
		else if (num > 1) cout << "not sure\n";
		else if(p) cout << "stack\n";
		else if (f) cout << "queue\n";	
		else if (fp) cout << "priority queue\n";

		while(aux.size())aux.pop();
		sacola.clear();
	}
}
