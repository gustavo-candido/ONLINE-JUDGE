#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
	/*
	 if(b==0) {
	  return a;
	 }
	 else return gdc(b, a%b);
	*/
}

int main ()
{
	int n, maxi, a, b, g;
	char s[10000], *t;
	vector<int> m;
	
	scanf("%d", &n);
	getchar();
	while(n--) {
		maxi = 1;
		gets(s);
		t = strtok(s, " ");
		while(t != NULL) {
			m.push_back(atoi(t));
			t = strtok(NULL, " ");
		}
		for(int i=0; i<(int)m.size(); i++)
			for(int j=i+1; j<(int)m.size(); j++) {
				g = gcd(m[i], m[j]);
				if(g > maxi) maxi = g;
			}
		printf("%d\n", maxi);
		m.clear();
	}
}
