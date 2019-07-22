#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    string a;

     cin >> N >> M;

     while(M--){
            cin >> a;
            if(a == "fechou") N++;
            else N--;
     }
     cout << N << endl;
}
