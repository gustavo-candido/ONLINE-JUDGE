#include <iostream>
 
using namespace std;
 
int main() {
 
    int t;
    double x, ans=0, p , q;
    
    cin >> t;
    while(t--) {
        cin >> p >> q;
        if(p == 1001) x = 1.5 * q;
        if(p == 1002) x = 2.5 * q;
        if(p == 1003) x = 3.5 * q;
        if(p == 1004) x = 4.5 * q;
        if(p == 1005) x = 5.5 * q;
        ans+=x;
    }
    printf("%.2lf\n", ans);
    return 0;
}