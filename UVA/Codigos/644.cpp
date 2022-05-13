#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<string> S;
	string aux;
	bool x=true;
	int c=1;
	while(cin >> aux) {
		if(aux.compare("9") == 0) {
			for(int i=0; i<(int)S.size(); i++) {
				for(int j=i+1; j<(int)S.size(); j++) {
				
					if(S[i].size() >= S[j].size() && S[i].compare(0,min(S[i].size(),S[j].size()), S[j]) == 0) {	
						x=false;
						i = (int)S.size();
						break;
					}
					else if(S[j].size() > S[i].size() && S[j].compare(0,min(S[j].size(),S[i].size()), S[i]) == 0) {	
						x=false;
						i = (int)S.size();
						break;
					}
				}
			}
			if(x) printf("Set %d is immediately decodable\n", c);
			else printf("Set %d is not immediately decodable\n", c);
			S.clear();
			x=true;
			c++;
		}
		else S.push_back(aux);
	}
}
