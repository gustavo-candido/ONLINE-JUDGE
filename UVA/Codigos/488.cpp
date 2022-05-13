#include <bits/stdc++.h>
using namespace std;

void print(int id, int x) {
	printf("%d", x);
	if(id+1 > x) {puts("");return;}
	print(id+1, x);
}


int main()
{
	int freq, ampli, t;
	
	cin >> t;
	
	while(t--) {
		cin >> ampli >> freq;
		for(int c=0;c<freq; c++) {
			for(int i=1; i<=ampli; i++) {
				print(1, i);	
			}
			for(int i=ampli-1; i>0; i--) {
				print(1, i);
			}
		    if(c+1 != freq)puts("");
		}
		if(t != 0) puts("");
	}
	
}
