#include <bits/stdc++.h>
using namespace std;

main()
{
	int  p, n, aux, h=0;
	bool f=true;
	
	cin >> p >> n;
	cin >> h; n--;
	while(n-- && f) {
		cin >> aux;
		if(abs(h-aux) > p)f=false;
		h = aux; 
	}
	if(f) cout << "YOU WIN\n";
	else cout << "GAME OVER\n";
}