#include <stdio.h>
#include <math.h>

int prim[10000] = {0};
void calcula_prim (int x) {
    int i=1, j=3, cont;
    prim[0] = 2;
    while(i!= x) {
        if(j%2 != 0) {
            cont=0;
            for (int c=1; c <= sqrt(j); c++) {
                if(j%c == 0) {
                    cont++;
                    if (cont > 1) break;
                }
            }
            if (cont == 1) {
                prim[i] = j;
                i++;
            }
        }
        j++;
    }

}
int main (){
    int n, aux[4000], ini, salt, key, x, akey;

    calcula_prim(4000);
    while(scanf("%d", &n)) {
        if (!n) break;
        ini = 1;
        for (int i=0; i<=n; i++) {
            aux[i] = i+1;
        }
        aux[n] = 1;
        ini = n;
        akey = 1;
        for (int i = 0; i < n-1; i++) {
            salt = prim[i];
            if(salt > n-i) {
                salt = salt % (n-i);
            }
            x = 0;
            key = ini;
            while(x != salt) {
                akey = key;
                key = aux[key];
                x++;
            }
            ini = akey;
            aux[akey] = aux[key];
        }
        printf("%d\n", aux[akey]);
    }
}
