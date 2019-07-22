#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    
    map<string, int> mm;
    bool line=0;
    string s;
    int n, tot;

    cin >> n;
    cin.ignore();
    getline(cin, s, '\n');

    while(n--) {
        mm.clear();
        if(line) cout << endl;
        tot=0;
        while(getline(cin, s, '\n') && s != "") mm[s]++, tot++;
          for (map<string, int>::iterator iter = mm.begin(); iter != mm.end(); iter++) {
            cout << iter->first << " " << fixed << setprecision(4) << (iter->second*100*1.0)/tot << endl;
        }
        line=1;
    }

}
