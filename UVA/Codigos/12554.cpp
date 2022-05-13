#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	vector<string>song;
	string s;
	vector<string> v;
	song.push_back("Happy");
	song.push_back("birthday");
	song.push_back("to");
	song.push_back("you");

	song.push_back("Happy");
	song.push_back("birthday");
	song.push_back("to");
	song.push_back("you");

	song.push_back("Happy");
	song.push_back("birthday");
	song.push_back("to");
	song.push_back("Rujia");

	song.push_back("Happy");
	song.push_back("birthday");
	song.push_back("to");
	song.push_back("you");

	cin >> n;
	int i=0;
	while(n--) {
 		cin >> s;
		v.push_back(s);
		cout << s << ": " << song[i++] << endl;
		if(i == 16)i = 0;	
	}
	int j=0;
	while(i != 0) {
		cout << v[j++] << ": " << song[i++] << endl;
		if(i == 16)i = 0;
		j%=v.size();
	}
}

