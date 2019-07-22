#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,cidades,pessoas;
    vector<int> v;

    cin>>cidades;
    for(int i=0;i<cidades;i++){
        v.assign(231,0);
        cin>>pessoas;
        for(int j=0;j<pessoas;j++){
            cin>>x;
            v[x]++;
        }
        bool f=0;
        for(int j=0;j<231;j++){
            while(v[j]>0){
            	if(f) cout << " ";
            	f=1;
                cout<<j;
                v[j]--;
            }
        }
        cout<< endl;
    }

    return 0;
}