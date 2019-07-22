#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int dr[] = {-2,-2, -1, -1,  1, 1,  2, 2};
int dc[] = {-1, 1, -2,  2, -2, 2, -1, 1};
map< pair<ii,ii>, int> ans;

ii s, f;

bool valid(int r, int c) {
    return !(r < 0 || r > 7 || c < 0 || c > 7);
}
void bfs()
{
    int dis[9][9];
    queue<ii>q;
    ii v;
    q.push(s);
    memset(dis, -1, sizeof dis);
    dis[s.first][s.second] = 0;
    while(q.size()) {
        v = q.front(); q.pop();
        ans[pair<ii,ii>(s,v)] = dis[v.first][v.second];
        if(f == v) {
            printf("To get from %c%d to %c%d takes %d knight moves.\n",'a'+s.first, s.second+1, 'a'+f.first, f.second+1, dis[f.first][f.second]);
            break;
        }
        for(int i=0; i<8; i++) {
            if(valid(v.first+dr[i], v.second+dc[i]) && dis[v.first+dr[i]][v.second+dc[i]] == -1) {
                dis[v.first+dr[i]][v.second+dc[i]] = dis[v.first][v.second]+1;
                q.push(ii(v.first+dr[i], v.second+dc[i]));
            }
        }
    }
}

int main()
{
    int x, y;
    char a, b;

    while(cin >> a >> x && !cin.eof()) {
        getchar();
        cin >> b >> y;
        getchar();
        s.first = a-'a'; s.second = x-1;
        f.first = b-'a'; f.second = y-1;
        if(ans.count(pair<ii,ii>(s,f))) printf("To get from %c%d to %c%d takes %d knight moves.\n",'a'+s.first, s.second+1, 'a'+f.first, f.second+1, ans[pair<ii,ii>(s,f)]);
        else bfs();
    }
}
