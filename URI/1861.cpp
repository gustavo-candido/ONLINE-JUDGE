#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    vector<string> killer, die;
    map<string, int> hall;
    string a, b;
    while(cin >> a >> b) {
        if(cin.eof()) break;
        killer.push_back(a);
        die.push_back(b);
    }

    int n = killer.size();

    sort(killer.begin(), killer.end());
    sort(die.begin(), die.end());

    for(int i=0; i<n; i++) {
        if(!binary_search(die.begin(), die.end(), killer[i])){
            if(hall.count(killer[i])) hall[killer[i]]++;
            else hall[killer[i]] = 1;
        }
        else {
            while(i+1<n && killer[i] == killer[i+1]) i++;
        }
    }

   cout << "HALL OF MURDERERS\n";

    for(map<string, int>::iterator i = hall.begin(); i != hall.end(); i++) {
        cout << i->first << " " << i->second << "\n";
    }
}
