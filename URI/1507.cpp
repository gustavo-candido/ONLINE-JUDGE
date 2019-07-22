#include <bits/stdc++.h>
using namespace std;

int main(){
    vector< vector<int> >box;
    bool f;
    int n, q, st, size_s, size_r;
    char s[100005], r[105];

    scanf("%d", &n);
    getchar();

    while(n--) {
            gets(s);
            box.resize(200);

            size_s = strlen(s);
            for(int i=0; i<size_s; i++) {
                box[s[i]-'A'].push_back(i);
            }

            scanf("%d", &q);
            getchar();
            while(q--) {
                f = true;
                st = 0;
                gets(r);
                size_r = strlen(r);
                for(int i=0; i<size_r; i++) {
                    int ind = lower_bound(box[r[i]-'A'].begin(),box[r[i]-'A'].end(), st) - box[r[i]-'A'].begin();
                    if(ind >= box[r[i]-'A'].size()) {
                        f = false;
                        break;
                    }
                    else {
                        st = box[r[i]-'A'][ind]+1;
                    }
                }
                printf("%s\n", (f == true)?"Yes":"No");
            }
            box.clear();
    }
}
