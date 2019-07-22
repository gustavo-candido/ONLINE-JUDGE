#include <bits/stdc++.h>
#define inf 0x3F3F3F3F
#define endl "\n"
#define off 1
using namespace std;

struct state{
    int u, d;
    string s;

    state() {u = d = 0; s = "";}
    state(int _u, int _d,  string _s) {u = _u; d = _d; s = _s;}
    bool operator > (state other) const {
            return d > other.d;
    }
};
typedef pair<int,string> ii;
typedef vector<ii> vii;

map<int, vii> grf;

int dijkstra(int s, int f) {
    int vis[grf.size()][28];
    priority_queue<state, vector<state>, greater<state> > pq;
    memset(vis, inf, sizeof vis);
    char aux = 'a' - 1;
    string ini;
    ini.push_back(aux);
    pq.push(state(s, 0, ini));
    for(int i=0; i<28; i++) vis[s][i] = 0;

    while(pq.size()) {
        state top = pq.top(); pq.pop();
        if(top.d > vis[top.u][top.s[0]-'a'+off]) continue;

        for(int i=0; i<(int)grf[top.u].size(); i++) {
            int v = grf[top.u][i].first;
            string w = grf[top.u][i].second;
            if(top.s[0] == w[0]) continue;
            if(top.d + w.size() < vis[v][w[0]-'a'+off]) {
               vis[v][w[0]-'a'+off] = top.d + w.size();
                pq.push(state(v, top.d + w.size(), w));
            }
        }
    }
    int mini = inf;

    for(int i=0; i<28; i++) {
        mini = min(mini, vis[f][i]);
    }
    return mini;
}
int main()
{
    int m;
    string s, f, o, d, w;
    map<string, int> dic;
    while(cin >> m && m != 0) {
        dic.clear();
        grf.clear();
        cin >> s >> f;
        dic[s] = dic.size()-1;
        dic[f] = dic.size()-1;
        grf[dic[s]] = vii();
        grf[dic[f]] = vii();
        for(int i=0; i<m; i++) {
            cin >> o >> d >> w;
            if(!dic.count(o)){
                dic[o] = dic.size()-1;
                grf[dic[o]] = vii();
            }
            if(!dic.count(d)){
                dic[d] = dic.size()-1;
                grf[dic[d]] = vii();
            }
            grf[dic[o]].push_back(ii(dic[d], w));
            grf[dic[d]].push_back(ii(dic[o], w));
        }
        int ans = inf;
        ans = sssp(dic[s], dic[f]);
        if(ans < inf) cout << ans << endl;
        else cout << "impossivel\n";
    }
}
