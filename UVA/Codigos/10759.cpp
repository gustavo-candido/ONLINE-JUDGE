#include <stdio.h>
#include <math.h>
#include <string.h>

unsigned long long int box[30][500],n, x, den, num, div;
unsigned long long int prob(unsigned long long int dice, unsigned long long int score) {
	if(dice == 0){
		if(score >= x) return 1;
		else return 0;
	}
	if(box[dice][score] != -1) return box[dice][score];
	
	unsigned long long int ans=0;
	for(int i=1; i<=6; i++) {
		ans+=box[dice][score] = prob(dice-1, score+i);
	}
	return box[dice][score] = ans;
}

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	while(scanf("%llu %llu", &n, &x) && (n || x)) {
		memset(box, -1, sizeof(box));
		den = pow(6,n);	
		num = prob(n, 0);
		div = gcd(den,num);
		if(num/div == 0)printf("%llu\n", num/div);
		else if(num/div == den/div) printf("%llu\n", num/div);
		else printf("%llu/%llu\n", num/div,den/div);
	}
}
