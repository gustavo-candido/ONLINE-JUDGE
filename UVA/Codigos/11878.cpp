#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, cont=0;
	char op, aux[10000];
	
	while(scanf("%d", &a) != EOF) {
		scanf("%c%d", &op, &b);
		scanf("%c", &aux[0]);
		scanf("%s", aux);
		if(strcmp(aux, "?") != 0){ 
			c = atoi(aux);
			if(op == '+' && a+b == c) cont++;
			else if(op == '-' && a-b == c) cont++;
		}
	}
	cout << cont << endl;
}
