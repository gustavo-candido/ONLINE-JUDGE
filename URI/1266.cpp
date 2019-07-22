#include <stdio.h>
 
int main ()
{
        int N, cerca[10000],cerca2[10000], x, y;
         
        while(scanf("%d", &N)) {
            if (!N) break;
            x = y = 0;
            scanf("%d", &cerca[0]);
            cerca2[0] = cerca[0];
            for (int i=1; i<N; i++) {
                scanf("%d", &cerca[i]);
                cerca2[i] = cerca[i];
                if (cerca[i]==0 && cerca[i-1]==0){
                    x++;
                    cerca[i] = 1;
                } 
            }
            if (cerca[0]==0 && cerca[N-1]==0){
                x++;
                cerca2[0] = 1;
                y++;
            }
            for(int i=1; i<N; i++) {
				if (cerca2[i]==0 && cerca2[i-1]==0){
                    y++;
                    cerca2[i] = 1;
                } 
			}
			
            
        
            if (x <= y)printf("%d\n", x); 
            else printf("%d\n", y);
        }
}
