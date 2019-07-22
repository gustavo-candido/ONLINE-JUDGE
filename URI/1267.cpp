#include <stdio.h>

int main ()
{
		int N, D, aux[666][666];
		bool TF, tf;
		
		while(scanf("%d %d", &N, &D)){
			if (!N && !D)break;
			TF = false;
			for(int i=0; i<D; i++) {
				for (int j=0; j<N; j++) {
					scanf("%d", &aux[i][j]);
				}
			}
			if (TF == false) {
				for (int i=0; i<N; i++) {
					tf = true;
					for (int j=0; j<D; j++) {
						if (aux[j][i]==0) tf = false;
					}
					if (tf == true) {
						TF = true;
						break;
					}
				}
			}
			if (TF == true) printf("yes\n");
			else printf("no\n");
		}
}
