#include <bits/stdc++.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return fabs(hypot(x2-x1, y2-y1));
}
int main()
{
    double x, y, a, b, t;
    int n;
    bool ans = false;

    scanf("%lf %lf %d", &x, &y, &n);
    for(int i=1; i<=n; i++) {
        scanf("%lf %lf %lf", &a, &b, &t);
        if(dist(x, y, a, b) < t) {
            if(ans) printf(" ");
            printf("%d", i);
            ans = true;
        }
    }
    if(!ans) puts("-1");
    else puts("");
}
