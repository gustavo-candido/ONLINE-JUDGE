#include <bits/stdc++.h>
using namespace std;

int s[3], h[3], a, b, x, tot;

int max_(int x){
    int i = s[x-1]+1;
    for(; i<53; i++)
        if(i != s[0] && i != s[1] && i != s[2] && i != h[0] && i != h[1]) return i;
    return -1;

}

int min_() {
  int  i=1;
    for(; i<53; i++)
        if(i != s[0] && i != s[1] && i != s[2] && i != h[0] && i != h[1]) return i;
    return -1;
}

int main()
{


    while(scanf("%d %d %d %d %d", &s[0], &s[1], &s[2], &h[0], &h[1]) && s[0]) {
        a = b = tot = 0;
        for(int i=0; i<3; i++)
            if(h[0] > s[i])a++;
        for(int i=0; i<3; i++)
            if(h[1] > s[i])b++;
        sort(&s[0], &s[3]);
        if(h[0] > h[1]) {
                    h[2] = h[0];
                    h[0] = h[1];
                    h[1] = h[2];
        }
        if(a > b) {
            h[2] = a;
            a = b;
            b = h[2];
        }
        tot=a+b;
        if(tot < 3) puts("-1");
        else if(tot == 3) {
            if(b == 3) printf("%d\n", max_(3));
            else puts("-1");
        }
        else if(tot == 4) {
            if(b == 3) printf("%d\n", max_(3));
            else printf("%d\n", max_(2));
        }
        else if(tot == 5) {
            printf("%d\n", max_(2));
        }
        else if(tot == 6) {
            printf("%d\n", min_());
        }
    }
}
