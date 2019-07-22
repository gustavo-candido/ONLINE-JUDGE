#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,tam,total;
    char lado;

    vector<int> dir;
    vector<int> esq;

    while(scanf("%d",&n) != EOF){

        dir.assign(61,0);
        esq.assign(61,0);
        for(int i=0;i<n;i++){
            scanf("%d %c",&tam,&lado);
            if(lado=='D'){
                dir[tam]++;
            } else{
                esq[tam]++;
            }
        }
        total=0;
        for(int i=0;i<61;i++){
            if(dir[i]>0 && esq[i]>0){
                total+=min(dir[i],esq[i]);
            }
        }
        printf("%d\n",total);
    }

    return 0;
}