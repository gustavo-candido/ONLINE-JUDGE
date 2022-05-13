#include <bits/stdc++.h>
using namespace std;

set<int> finger;
map<int,set<char> > m;
void inic()
{
	m[1].insert('q'); 
	m[1].insert('a');
	m[1].insert('z');
	
	m[2].insert('w'); 
	m[2].insert('s');
	m[2].insert('x');
	
	m[3].insert('e'); 
	m[3].insert('d');
	m[3].insert('c');
	
	m[4].insert('r'); 
	m[4].insert('f');
	m[4].insert('v');
	m[4].insert('t'); 
	m[4].insert('g');
	m[4].insert('b');
	
	m[5].insert(' ');
	
	m[6].insert(' ');
	
	m[7].insert('y'); 
	m[7].insert('h');
	m[7].insert('n');
	m[7].insert('u'); 
	m[7].insert('j');
	m[7].insert('m');
	
	m[8].insert('i'); 
	m[8].insert('k');
	m[8].insert(',');
	
	m[9].insert('o'); 
	m[9].insert('l');
	m[9].insert('.');
	
	m[10].insert('p'); 
	m[10].insert(';');
	m[10].insert('/');
	
	/*for(map<int,set<char> >::iterator i= m.begin(); i!=m.end(); i++) {
		for(set<char>::iterator j = m[i->first].begin(); j!=m[i->first].end(); j++) {
			cout<< *j << endl;
		}
	} */
}

int main()
{
	
	int F, N, aux;
	string A;
	set<string> maxi_word;
	int tam=0, maxi_tam=0;
	bool can;
	inic();
	while(scanf("%d", &F) != EOF) {
		scanf("%d", &N);
		tam = maxi_tam = 0;
		finger.clear();
		maxi_word.clear();
		for(int i=0; i<F; i++) {
			scanf("%d", &aux);
			finger.insert(aux);
		}
		getchar();
		for(int i=0; i<N; i++) { 

			cin >> A;
			for(int i=0; i<(int)A.size(); i++) {
				
				for(int j=1; j<=10; j++) {
					if(finger.count(j)) continue;
					if(!m[j].count(A[i])){
						can = false;
					}
					else {can = true;break;}
				}
				
				if(!can) break;
			}
			
			if(can) {
				tam = A.size();
				if(tam > maxi_tam) {
					maxi_tam = tam;
					maxi_word.clear();
					maxi_word.insert(A);
				}
				else if(tam == maxi_tam) maxi_word.insert(A);
			}
		}
		cout << maxi_word.size()<< endl;
		for(set<string>::iterator i=maxi_word.begin(); i!=maxi_word.end(); i++) cout << *i << endl;
	}
}
