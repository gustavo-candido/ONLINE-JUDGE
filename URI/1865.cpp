#include <iostream>
 
using namespace std;
 
int main() {
 
    int c, n;
    string name;
    
    cin >> c;
    while(c--) {
        cin >> name >> n;
        if(name == "Thor") cout << "Y\n";
        else cout <<"N\n";
    }
 
    return 0;
}