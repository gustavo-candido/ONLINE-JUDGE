#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string a, b;

    scanf("%d", &n);
    getchar();

    while(n--) {
        cin >> a >> b;

        if(a == "tesoura" && b == "papel") puts("rajesh");
        else if(a == "papel" && b == "pedra") puts("rajesh");
        else if(a == "pedra" && b == "lagarto") puts("rajesh");
        else if(a == "lagarto" && b == "spock") puts("rajesh");
        else if(a == "spock" && b == "tesoura") puts("rajesh");
        else if(a == "tesoura" && b == "lagarto") puts("rajesh");
        else if(a == "lagarto" && b == "papel") puts("rajesh");
        else if(a == "papel" && b == "spock") puts("rajesh");
        else if(a == "spock" && b == "pedra") puts("rajesh");
        else if(a == "pedra" && b == "tesoura") puts("rajesh");
        swap(a, b);
        if(a == "tesoura" && b == "papel") puts("sheldon");
        else if(a == "papel" && b == "pedra") puts("sheldon");
        else if(a == "pedra" && b == "lagarto") puts("sheldon");
        else if(a == "lagarto" && b == "spock") puts("sheldon");
        else if(a == "spock" && b == "tesoura") puts("sheldon");
        else if(a == "tesoura" && b == "lagarto") puts("sheldon");
        else if(a == "lagarto" && b == "papel") puts("sheldon");
        else if(a == "papel" && b == "spock") puts("sheldon");
        else if(a == "spock" && b == "pedra") puts("sheldon");
        else if(a == "pedra" && b == "tesoura") puts("sheldon");
        else if(a == b) puts("empate");
    }
}
