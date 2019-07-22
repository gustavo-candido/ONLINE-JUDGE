#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, line, page, x;
    char s[5000];
    while(scanf("%d %d %d", &a, &b, &c) != EOF) {
        getchar();
        line = page = 1;
        x = 0;

        for(int i=0; i<a; i++) {
            if(i) x++;
            scanf("%s", s);
            x+=strlen(s);
            if(x > c) {line++; x = strlen(s);}
            if(line > b) {page++; line = 1;}
        }
        printf("%d\n", page);
    }
}
