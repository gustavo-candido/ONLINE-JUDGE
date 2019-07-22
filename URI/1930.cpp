#include <iostream>
 
using namespace std;
 
int main() {
 
    int n, c=0;
    
    for(int i=0; i<4; i++) {
        cin >> n;
        c+=n;
    }
    cout << c-3 << endl;
 
    return 0;
}