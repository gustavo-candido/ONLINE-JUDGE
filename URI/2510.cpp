#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s, x = "Batmain";
    int t;

    cin >> t;
    cin.ignore();

    while(t--) {
        getline(cin, s);

        printf("%c\n", (s == x)?'N':'Y');
    }
}
