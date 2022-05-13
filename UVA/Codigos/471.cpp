#include <bits/stdc++.h>
const long long limit = 9876543210LL;
using namespace std;

int main()
{
	long long int t, n, used;
	bool f=false;
	scanf("%d", &t);

	while(t--){
		if(f) puts("");
		scanf("%lld", &n);

		for(long long int b = 1; b*n <= limit; b++) {	
			f = true;
			long long int tmp, a = n*b;
			used = 0;
			tmp = a; 
			while(tmp) {
				if(used & (1<<tmp%10)) {
					f = false;	
					break;
				}
				used |=  (1<<tmp%10);
				tmp/=10;
			} 
			if(!f) continue;
			tmp = b;
			used = 0;
			 while(tmp) {
				if(used & (1<<tmp%10)) {
					f = false;	
					break;
				}
				used |=  (1<<tmp%10);
				tmp/=10;
			} 
			if(!f)continue;
			printf("%lld / %lld = %lld\n", a, b, n);
		}
		f = true;
	}

}
