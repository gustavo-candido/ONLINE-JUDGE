#include <stdio.h>

int mdc(int a, int b) {
    if (b == 0) return a;
    else return mdc(b, a % b);
}

int main(){
    int x,y,z;
    while(scanf("%d %d %d", &x, &y, &z) != EOF){
        printf("tripla");
    if(x*x==y*y+z*z || y*y==x*x+z*z || z*z==x*x+y*y){
        printf(" pitagorica");
        if(mdc(mdc(x,y),z)==1) printf(" primitiva");
    }
    printf("\n");
    }
    return 0;
}