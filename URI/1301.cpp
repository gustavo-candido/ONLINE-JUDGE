#include <bits/stdc++.h>
#define lsb(x) x&(-x)
using namespace std;

const int N = 100005;

typedef struct BIT {
    int ft[N], n;

    void init() {
        memset(ft, 0, sizeof ft);
    }

    void update(int i, int x) {
        for(; i<=n; i+=lsb(i)) ft[i]+=x;
    }   

    int sum(int i) {
        int ans=0;
        for(; i; i-=lsb(i)) ans+=ft[i];
        return ans;
    }

    int sum(int i, int j) {
        return sum(j) - sum(i-1);
    }
} BIT;

int n, k, v[N];
char ans[N];
BIT neg, zero;

int getnum(int x) {
    if(x>0) return 1;
    if(!x) return 0;
    return -1;
}

int main()
{
    char op;
    int a, b;

    while(scanf("%d %d", &n, &k) != EOF) {
        neg.n = zero.n = n;
        neg.init();
        zero.init();
        for(int i=1; i<=n; i++) {
            int x; scanf("%d", &x);
            v[i] = getnum(x);
            if(v[i] < 0) neg.update(i, 1);
            if(!v[i]) zero.update(i, 1);           
        }
        getchar();

        int idx=0;
        for(int i=0; i<k; i++) {
            scanf("%c %d %d", &op, &a, &b);
            getchar();
            if(op == 'C') {
                int x = getnum(b);
                if(!v[a]) zero.update(a, -1);
                if(v[a] == -1) neg.update(a, -1);
                if(!x) zero.update(a, 1);
                if(x == -1) neg.update(a, 1);
                v[a] = x;
            }
            if(op == 'P') {
                if(zero.sum(a,b)) ans[idx] = '0';
                else if(neg.sum(a,b)%2 == 0) ans[idx] = '+';
                else ans[idx] = '-';
                idx++;
            }
        }
        ans[idx] = '\0';
        puts(ans);
    }
}




