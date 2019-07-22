#include <bits/stdc++.h>
using namespace std;

main()
{
	int t, x;
	
	cin >> t;

	while(t--){
		cin >> x;
		if(2015 - x > 0 ) cout << 2015-x << " D.C.\n";
		else cout << abs(2015-x)+1 << " A.C.\n";
	}
}