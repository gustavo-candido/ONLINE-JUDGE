#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, op, x, aux;
	stack<int> pilha;	
	queue<int> fila;
	priority_queue<int>pq;
	bool a, b, c;
	while(scanf("%d", &n) != EOF) {
		a = b = c = true;
		while(n--) {
			scanf("%d %d", &op, &x);
			if(op == 1) {
				if(a) pilha.push(x);
				if(b) fila.push(x);
				if(c) pq.push(x);
			}
			else {
				if(a && (pilha.empty() || pilha.top() != x)) a = false;
				else if(a) pilha.pop();
				if(b && (fila.empty() || fila.front() != x)) b = false;
				else if(b) fila.pop();
				if(c && (pq.empty() || pq.top() != x)) c = false;
				else if(c) pq.pop();
			}
		}
		if(a == true && b == false && c == false) puts("stack");
		else if(a == false && b == true && c == false) puts("queue");
		else if(a == false && b == false && c == true) puts("priority queue");
		else if(a == false && b == false && c == false) puts("impossible");
		else puts("not sure");

		while(!pilha.empty()) pilha.pop();
		while(!fila.empty())fila.pop();
		while(!pq.empty()) pq.pop();
	}
}
