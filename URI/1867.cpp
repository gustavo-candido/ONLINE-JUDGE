#include <bits/stdc++.h>
using namespace std;

int num(string a) {
    int x=0;

    for(int i=0; i<(int)a.size(); i++) {
        x+=(a[i]-'0');
        if(x > 9) {
            char b[5];
            sprintf(b, "%d", x);
            x = num(b);
        }
    }
    return x;
}

int main()
{
 string a, b;
 int x, y;

  while(cin >> a >> b && !(a == b && b == "0")) {
     x = num(a);
     y = num(b);
     if(x > y) puts("1");
     else if(x == y) puts("0");
     else if(x < y) puts("2");
  }
}
