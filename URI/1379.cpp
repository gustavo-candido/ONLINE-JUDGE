#include <stdio.h>

int main ()
{
	int A, B, C;
		
	while(scanf("%d %d", &A, &B)) {
		if(A==0 && B==0) break;
		C = B-A;
		printf("%d\n", A-C);
	}
}
