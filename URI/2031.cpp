#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, f;
    string a, b;

    cin >> t;

    while(t--) {
        cin >> a >> b;

        if(a == "ataque") {
             if(b == "pedra" || b == "papel") f = 1;///1 ganha
             if(b == "ataque") f = 4; ///aniquilação
        }
        else if(a == "pedra") {
            if(b == "ataque") f = 2;///2 ganha
            else if (b == "papel") f = 1;///1 ganha
            else if (b == "pedra") f = 0; ///ninguem ganha
        }
        else if(a == "papel") {
            if(b == "pedra" || b == "ataque") f  = 2; ///2 ganha
            else if(b == "papel") f = 3; ///Ambos ganham
        }
        if(f == 0) cout << "Sem ganhador" << endl;
        else if(f == 1) cout << "Jogador 1 venceu" << endl;
        else if(f == 2) cout << "Jogador 2 venceu" << endl;
        else if(f == 3) cout << "Ambos venceram" << endl;
        else if(f == 4) cout << "Aniquilacao mutua" << endl;
    }
}
