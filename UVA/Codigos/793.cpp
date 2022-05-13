#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi p;

void inicia (int N) {
	p.resize(N+1);
	for(int i=0; i<=N; i++) p[i] = i;
}

int find(int i) {
	return (i == p[i]) ? i : p[i] = find(p[i]); 
}

bool mesma (int i, int j) {
	return find(i) == find(j);
}

void uni (int i, int j) {
	p[find(i)] = find(j);
}

int main ()
{
   int N, err, acc, arest, ori, dest;
   char op;
   bool x;
   scanf("%d", &N);
   getchar();
   getchar();
   while(N--) {
	    scanf("%d", &arest);
	    getchar();
		inicia(arest);
		if(N>0){
			acc = err = 0;
			while(scanf("%c", &op)) {
				if(op == '\n') break;
				scanf(" %d %d", &ori, &dest);
				getchar();
				if (op == 'c') uni(ori, dest);
				else {
					if(mesma(ori, dest)) acc++; 
					else err++;
				}
			}
		}
		else {
			acc = err = 0;
			while(scanf("%c", &op) != EOF) {
			  scanf(" %d %d", &ori, &dest);
			  char a;
			  if(scanf("%c", &a)==EOF) break;
			  if (op == 'c') uni(ori, dest);
				else {
					if(mesma(ori, dest)) acc++; 
					else err++;
				}
			}
		}
		cout << acc  << "," << err << endl;
		if (N > 0) cout << endl;
		p.clear();
   }	
}
