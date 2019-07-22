#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef pair<int,int> ii;

bool cmp(ii a, ii b) {
    if(a.S - a.F < b.S - b.F) return true;
    else return false;
}
int main()
{
    int n, g, a, b, score;
    vector<ii>v;

    while(scanf("%d %d", &n, &g) != EOF) {
            v.clear();
            score = 0;
            for(int i=0; i<n; i++) {
                scanf("%d %d", &a, &b);

                if(a > b) score+=3;
                else if(a == b && g > 0) {
                    score+=3;
                    g--;
                }
                else if(a == b && g <= 0) {
                    score++;
                }
                else v.push_back(ii(a,b));
            }
            sort(v.begin(), v.end(), cmp);
            for(int i=0; i < (int)v.size(); i++) {
                if(g >= v[i].S+1 - v[i].F) {
                    g-=v[i].S+1 - v[i].F;
                    score+=3;
                }
                else if(g >= v[i].S - v[i].F) {
                    g-=v[i].S - v[i].F;
                    score++;
                }
                else break;
            }
            printf("%d\n", score);
    }
}
