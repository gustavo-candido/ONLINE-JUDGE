#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a, b;
    char x[50];

    while(scanf("%lld %lld", &a, &b) && a && b) {
        sprintf(x, "%lld", a+b);
        for(int i=0;i<strlen(x); i++)
            if(x[i] != '0') cout << x[i];
        puts("");
    }
}
