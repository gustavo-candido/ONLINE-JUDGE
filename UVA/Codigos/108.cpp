#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int n, A[110][110], subRect;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
			if (i > 0) A[i][j] += A[i - 1][j];
			if (j > 0) A[i][j] += A[i][j - 1];
			if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];

		}
		
		int maxSubRect = -127*100*100;

		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				for (int k = i; k < n; k++) 
					for (int l = j; l < n; l++) {
						subRect = A[k][l];
						if (i > 0) subRect -= A[i - 1][l];
						if (j > 0) subRect -= A[k][j - 1];
						if (i > 0 && j > 0) subRect += A[i - 1][j - 1];
						maxSubRect = max(maxSubRect, subRect);
					}
					
		cout << maxSubRect << endl;
}
