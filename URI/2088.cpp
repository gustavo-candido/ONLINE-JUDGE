  #include <bits/stdc++.h>
  #define INF 1e15
  #define f first
  #define s second
  using namespace std;

  typedef pair<int,int> ii;
  ii foco[16];
  int n;
  double grf[16][16], dp[1 << 16][16];
  bool vis[1 << 16][16];

  double tsp(int id, int k) {
        if(k == (1<<n)-1) return grf[id][0];
        if(vis[k][id]) return dp[k][id];
        double ans = INF;
        for(int i=0; i<n; i++) {
            if(!(k&(1<<i)))ans = min(ans, tsp(i, k|(1<<i))+grf[id][i]);
        }
        vis[k][id] = 1;
        return dp[k][id] = ans;
  }

  int main()
  {
      while(scanf("%d", &n) && n) {
        n++;
        for(int i=0; i<n; i++) scanf("%d %d", &foco[i].f, &foco[i].s);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                grf[i][j] = hypot(foco[i].f - foco[j].f, foco[i].s - foco[j].s);
            }
        }
        memset(vis, 0, sizeof vis);

        printf("%.2lf\n", tsp(0, 0));
      }
  }
