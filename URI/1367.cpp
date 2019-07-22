#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, penalit[30], x, tmp, score;
    bool pass[30];
    char result[20], id;

    while(scanf("%d", &n) && n) {
        getchar();
        score = tmp = 0;
        memset(pass, 0, sizeof pass);
        memset(penalit, 0, sizeof penalit);

        while(n--) {
            scanf("%c %d %s", &id, &x, result);
            getchar();
            if(strcmp(result, "incorrect") == 0) penalit[id-'A']+=20;
            else {
                score++;
                tmp+=x+penalit[id-'A'];
            }
        }
        printf("%d %d\n", score, tmp);
    }
}
