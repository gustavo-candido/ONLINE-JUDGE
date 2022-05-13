#include <bits/stdc++.h>

main() {
    int tam, met, x, y, xa, ya;
    long long pos, c = 1, i = 1;
    while(scanf("%d %lld", &tam, &pos), tam!=0 && pos!=0){
        met = tam / 2;
        c = i = 1;
        x = y = met;
        while(1){
            if(c == pos){
                xa = x;
                ya = y;
                break;
            }
            if(pos > c && pos <= c + i){
                ya = y;
                xa = x - (pos - c);
                break;
            }
            else{
                x -= i;
                c += i;
            }
            if(pos > c && pos <= c + i){
                xa = x;
                ya = y - (pos - c);
                break;
            }
            else{
                y -= i;
                c += i;
            }
            i++;
            if(pos > c && pos <= c + i){
                ya = y;
                xa = x + (pos - c);
                break;
            }
            else{
                x += i;
                c += i;
            }
            if(pos > c && pos <= c + i){
                xa = x;
                ya = y + (pos - c);
                break;
            }
            else{
                y += i;
                c += i;
            }
            i++;
        }
        printf("Line = %d, column = %d.\n", tam-xa, ya+1);
    }  
}
