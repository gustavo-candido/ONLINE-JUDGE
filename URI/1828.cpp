#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int T;
    string a, b;
    int f;
    cin >> T; getchar();
    for(int i=1; i<=T; i++) {
        cin >> a >> b;
        if(a == "tesoura") {
           if(b == "papel" || b == "lagarto") f = 1;
           else if(b == "pedra" || b == "Spock") f = 0;
        }
        else if(a == "papel") {
            if(b == "tesoura" || b == "lagarto") f = 0;
            else if(b == "pedra" || b == "Spock") f = 1;
        }
	else if(a == "pedra") {
	    if(b == "papel" || b == "Spock") f=0;
	    else if(b == "lagarto" || b == "tesoura")f=1;
	}
	else if(a == "lagarto") {
		if(b == "pedra" || b == "tesoura") f=0;
		else if(b == "Spock" || b == "papel") f=1;
	
        }
	else if(a == "Spock") {
		if(b == "lagarto" || b == "papel") f = 0;
		else if(b == "tesoura" || b == "pedra") f = 1;
	}
	if(a == b) f=2;
	cout << "Caso #" << i << ": ";
	if(f == 1) cout << "Bazinga!" << endl;
	else if(f == 0) cout << "Raj trapaceou!" << endl;
	else if(f == 2) cout << "De novo!"<< endl;
    }
 
    return 0;
}