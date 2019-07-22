#include <stdio.h>
#include <string.h>
main ()
{
	char A[200];
	int jing, i, y, tam;
	double x;
	while (gets(A) != NULL) {
		if (A[0] == '*') break;
		for (i=0, x=0, y=0; i<strlen(A); i++) {
			if (A[i] == '/') {
				if (x==1.0) y++;
				x=0.0;
			}
			else if (A[i] == 'W') x+=1; 
			else if (A[i] == 'H') x = x + (1.0/2);
			else if (A[i] == 'Q') x = x + (1.0/4);
			else if (A[i] == 'E') x = x + (1.0/8);
			else if (A[i] == 'S') x = x + (1.0/16);
			else if (A[i] == 'T') x = x + (1.0/32);
			else if (A[i] == 'X') x = x + (1.0/64);
		}
		printf("%d\n", y);
	}
}
