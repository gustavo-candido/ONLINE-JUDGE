#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char string [1100], reversa[1100];
	int n, sn, l, o =0;
	scanf("%d", &n);
	getchar();
	while(n--){
		gets(string);
		sn = strlen(string);
		for(int j = 0; j<sn; j++){
			if((string[j]>=65 && string[j]<=90) || (string[j]>=97 && string[j]<=122) ){
				string[j] +=3;

				}


			}

      
        l=0;
		for(int k = sn-1; k>=0; k--){
			reversa[l] = string[k];
			l++;


		}
		
		reversa[l] = '\0';
		

		for(int m = sn/2; m<=sn; m++){
			
				reversa[m] -=1;
				
				
		}
		reversa[sn] = '\0';
		printf("%s\n", reversa);




	}
	return 0;
}
