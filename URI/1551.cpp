#include <stdio.h>
#include <set>
using namespace std;

int main ()
{
    int N;
    char aux;
    set <char> myset;

    scanf("%d ", &N);
    for (int i=0; i<N; i++) {
        while (1) {
            scanf("%c", &aux);
            if (aux == '\n') break;
            if(aux!=' ' && aux!=',')myset.insert(aux);
        }
        if (myset.size() == 26) printf("frase completa\n");
        else if (myset.size() >= 13) printf("frase quase completa\n");
        else printf("frase mal elaborada\n");
        myset.clear();
    }
}
