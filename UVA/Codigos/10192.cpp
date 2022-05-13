#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int mem[MAX][MAX], C=1;
string obj, s;


int main()
{

	while(getline(cin, s) && s.compare("#") != 0){
		getline(cin, obj);

		mem[0][0] = 0;
		for(int i=0; i<(int)obj.size(); i++) mem[0][i]  = 0;
		for(int i=0; i<(int)s.size(); i++) mem[i][0]  = 0;

		for(int i=1; i<=(int)obj.size(); i++) {
			for(int j=1; j<=(int)s.size(); j++) {
				if(obj[i-1] == s[j-1]) mem[i][j] =  mem[i-1][j-1]+1;
				else mem[i][j] = max(max(mem[i-1][j],mem[i][j-1]), mem[i-1][j-1]);
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n", C, mem[obj.size()][s.size()]);
		C++;
	}

}
