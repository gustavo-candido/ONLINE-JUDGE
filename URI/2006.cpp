#include <iostream>
 
using namespace std;
 
int main() {
 
    int t, v, c=0;
    
    cin >> t;
    for(int i=0; i<5; i++) {
        cin >> v;
        if(v == t)c++;
    }
    cout << c << endl;
    return 0;
}