#include <bits/stdc++.h>
using namespace std;

int N;
vector<int>a, d, h;
map <pair<int, pair<int, pair<int, pair<int,int> > > >, int> m;
int invoca(int id, int A, int D, int H, int card) {
    if(A == 0 && D == 0 && H == 0 && card > 1) return 1;
    if(id >= N) return 0;
    if(A < 0 || D < 0 || H < 0) return 0;
    if(m.count(make_pair(id, make_pair(A, make_pair(D, make_pair(H, card)))))) return m[make_pair(id, make_pair(A, make_pair(D, make_pair(H, card))))];
    return m[make_pair(id, make_pair(A, make_pair(D, make_pair(H, card))))] = max(invoca(id+1, A-a[id], D-d[id], H-h[id], card+1),invoca(id+1, A, D, H, card));
}

int main()
{
    int A, D, H;
    cin >> N >> A >> D >> H;
    a.resize(N);
    d.resize(N);
    h.resize(N);
    for(int i=0; i<N; i++) {
        cin >> a[i] >> d[i] >> h[i];
    }
    if(invoca(0, A, D, H, 0) != 0) cout << "Y\n";
    else cout << "N\n";
}
