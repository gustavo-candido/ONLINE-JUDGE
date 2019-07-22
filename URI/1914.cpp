#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   int t;
   string a, x, b, y;
   long long int i, j;
   
   cin >> t;getchar();
   while(t--){
       cin >> a >> x >> b >> y >> i >> j;getchar();
       if((i+j) % 2 == 0 && x == "PAR") cout << a << endl;
       else if((i+j) % 2 != 0 && x == "IMPAR") cout << a << endl;
       else cout << b << endl;
   }
 
    return 0;
}