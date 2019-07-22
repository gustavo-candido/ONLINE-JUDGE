#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    double t;
    string s;

    cin >> T;getchar();
    while(T--) {
        cin >> s;
        t = s.size()/100.0;
         printf("%.2F\n", t);
    }


}
