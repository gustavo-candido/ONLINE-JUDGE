#include <bits/stdc++.h>
using namespace std;

int main()
{
	int sen, x, N, n, max_dif;
	
	scanf("%d", &N);
	
	while(N--) {
		scanf("%d", &n);
		scanf("%d", &sen);
		max_dif = -100000000;
		n--;
		while(n--) {
			scanf("%d", &x);
			if(sen - x> max_dif) {max_dif = sen - x;}
			if(x > sen) sen = x;
		}
		cout << max_dif << endl;
	}
}
