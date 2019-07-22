#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[20], b[20];
    long long int x;

    while(scanf("%s", a) && strcmp(a, "-1") !=0) {
        if(a[1] == 'x') {
                for(int i=2; i<strlen(a); i++) b[i-2]=a[i];
                b[strlen(a)-2] = '\0';
                sscanf(b, "%llX", &x);
                printf("%lld\n", x);
        }
        else {
            sscanf(a, "%lld", &x);
            printf("0x%llX\n", x);
        }
    }
}
