#include <bits/stdc++.h>
using namespace std;

int main()
{
	char n[100];
	int ans;
	while(gets(n) && strcmp(n,"0")) {
		while(strlen(n) > 1) 
			{ans=0;
			for(int i=0; i<strlen(n); i++) ans+=(n[i]-'0');
			sprintf(n, "%d", ans);
		}
		cout << n << endl;
	}
}
