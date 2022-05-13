#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int  P;
	long double C = C = logl(10)/logl(2);
	while(scanf("%lld",&P) == 1)
	{
		long double T, LP, LPP;
		LP = logl(P)/logl(2);
		
		LPP = logl(P+1)/logl(2);
		T = floorl( log10l(P)) + 2;

		for (; ceill(LP + T*C) != floorl(LPP + T*C); T++);

		cout << (long long int)floorl(LPP + T*C) << '\n';

		

	}


	return 0;
}
