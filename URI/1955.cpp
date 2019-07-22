#include <bits/stdc++.h>
using namespace std;

int V;
vector< vector<int> > box;

bool is_bipartide() {
    queue<int> q;
    vector<int> vis;
    vis.assign(V, -1);
    q.push(0);
    vis[0] = 0;
    while(q.size()) {
        int top = q.front(); q.pop();
        for(int i=0; i<box[top].size(); i++) {
            int u = box[top][i];
            if(vis[u] == -1) {
               q.push(u);
               vis[u] = 1 - vis[top];
            }
            else if(vis[u] == vis[top])return false;
        }
    }
    return true;
}

int main()
{
    int aux;
    cin >> V;
    box.resize(V);

    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++) {
            cin >> aux;
            if(aux==0) box[i].push_back(j);
        }
    if(is_bipartide()) cout <<"Bazinga!\n";
    else cout <<"Fail!\n";
}
