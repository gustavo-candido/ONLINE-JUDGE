#include <bits/stdc++.h>
using namespace std;

int main()
{
    int C=0, pos, sub, up;
    string p, t;

    while(getline(cin, p) && !cin.eof()) {
        sub = pos=0;
        getline(cin, t);
        while((pos = t.find(p, pos)) != -1) {
            pos+=p.size();
            sub++;
            if(pos != -1) up = pos;
        }
        printf("Caso #%d:\n", ++C);
        if(sub != 0) {
                printf("Qtd.Subsequencias: %d\n", sub);
                printf("Pos: %d\n\n", up-p.size()+1);
        }
        else puts("Nao existe subsequencia\n");
    }
}
