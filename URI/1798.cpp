#include <bits/stdc++.h>
using namespace std;

int n, m, box[2001], cut[1001], val[1001];

int main()
{

    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++) scanf("%d %d", &cut[i], &val[i]);

    box[0] = 0;
    for(int i = 1; i <= m; i++) {
        box[i] = box[i-1];
        for(int j = 0; j<n; j++) {
            if(i - cut[j] >= 0) {
                    box[i] = max(box[i], box[i-cut[j]]+val[j]);
            }
        }
    }

    printf("%d\n", box[m]);
}
