#include <bits/stdc++.h>
using namespace std;

int bin[10], c[6];
char ans[][10] = { {"BCG"},{"BGC"}, {"CBG"}, {"CGB"}, {"GBC"}, {"GCB"} };
int main()
{
	
	while(cin >> bin[0] && !cin.eof()){
		for(int i=1; i<9; i++) cin >> bin[i];
		c[0] = bin[0]+bin[3]+bin[6] - bin[0] + bin[2]+bin[5]+bin[8] - bin[5] + bin[1]+bin[4]+bin[7] - bin[7];//BCG
		c[1] = bin[0]+bin[3]+bin[6] - bin[0] + bin[1]+bin[4]+bin[7] - bin[4] + bin[2]+bin[5]+bin[8] - bin[8];//BGC
		c[2] = bin[2]+bin[5]+bin[8] - bin[2] + bin[0]+bin[3]+bin[6] - bin[3] + bin[1]+bin[4]+bin[7] - bin[7];//CBG
		c[3] = bin[2]+bin[5]+bin[8] - bin[2] + bin[1]+bin[4]+bin[7] - bin[4] + bin[0]+bin[3]+bin[6] - bin[6];//CGB
		c[4] = bin[1]+bin[4]+bin[7] - bin[1] + bin[0]+bin[3]+bin[6] - bin[3] + bin[2]+bin[5]+bin[8] - bin[8];//GBC
		c[5] = bin[1]+bin[4]+bin[7] - bin[1] + bin[2]+bin[5]+bin[8] - bin[5] + bin[0]+bin[3]+bin[6] - bin[6];//GCB
		
		int P0 = 0;
		
		for(int i=1; i<6; i++) 
			if(c[i] < c[P0]) P0 = i;
		
		cout << ans[P0] <<" "<< c[P0] << endl;
	}
	
}
