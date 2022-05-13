#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int skwen, x;
	char A[10000];
	
	while(gets(A) != NULL) {
		if(strcmp(A, "0") == 0) break;
		skwen = 0;
		for(int i=0; i<(int)strlen(A); i++) {
			x = (A[i]-48) * (pow(2, strlen(A)-i)-1);
			skwen+=x;
		//	printf("--- %d\n",x);
		}
		printf("%d\n", skwen);
	} 
}
