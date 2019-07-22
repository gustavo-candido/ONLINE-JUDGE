#include <bits/stdc++.h>

int main()
{
    int v[4], t;

    scanf("%d %d %d %d", &v[0], &v[1], &v[2], &v[3]);

    t = 0;

    for(int i=0; i<4; i++) t+=v[i];

    int ans = 10000000;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++)if(i != j) ans = std::min(ans, abs((t-(v[i]+v[j]))- (v[i]+v[j])));
    }
    printf("%d\n", ans);
}
