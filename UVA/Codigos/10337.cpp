#include <bits/stdc++.h>
using namespace std;

int x, sky[1010][1010], mem[1010][1010];

int fly(int r, int c) {
	if(r == 9 && c == x) return 0 ;
	if(r > 9 || r < 0 || c > x-1) return 100000000;
    if(mem[r][c] != -1) return mem[r][c];
	return mem[r][c] = min(fly(r+1, c+1)+60,  min(fly(r, c+1)+30, fly(r-1, c+1)+20))-sky[r][c];
}
int main()
{
	int t;
	
	cin >> t;
	
	while(t--) {
		cin >> x; x/=100;
		
		for(int i=0; i<10; i++) {
			for(int j=0; j<x; j++) {
				cin >> sky[i][j];
			}
		}
		memset(mem, -1, sizeof(mem));
		cout << fly(9,0)<< endl << endl;
	}
}
