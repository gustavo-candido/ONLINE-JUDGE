#include<stdio.h>
#include<math.h>
main () {
    int n, vet[45],i;
    scanf("%d", &n);
    vet[0]=0;
    vet[1]=1;
        for(i=2;i<n;i++){
            vet[i]=vet[i-1]+vet[i-2];
           }
        for(i=0;i<n;i++){
            if((n-i)==1){
              printf("%d\n",vet[i]);
            } else {
              printf("%d ",vet[i]);
           }
         }
}