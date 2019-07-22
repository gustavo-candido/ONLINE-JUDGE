#include <bits/stdc++.h>
using namespace std;

int main()
{

	char last;
	int n, i;
	string line, aux;
	deque<string> buffer;


	while(cin>>line) {
		if(cin.eof()) break;
		aux="";
		last=']';

		n = line.size();

		for(i=0; i<n; i++) {
				if(line[i] == '[' || line[i] == ']'){
					last = line[i];
					break;
				}
				aux+=line[i];
		}
		i++;
		buffer.push_back(aux);

		aux="";

		for(; i<n; i++) {
			if(line[i] == '[' || line[i] == ']'){
				if(last == '[') {
					buffer.push_front(aux);
				}
				else buffer.push_back(aux);

				aux="";
				last = line[i];
				continue;
			}
			aux+=line[i];
		}

		if(last == '[') {
			buffer.push_front(aux);
		}
		else buffer.push_back(aux);

		aux="";


		for(auto s: buffer) cout << s;

		cout << "\n";
		buffer.clear();

	}
}