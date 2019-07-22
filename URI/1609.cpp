#include <stdio.h>
#include <stdlib.h>

int vet[10005], aux[10005];
void merge(int inicio, int n){
    if(n<=1) return;
    merge(inicio, n/2);
    merge(inicio+n/2, n-n/2);
    int a=0, b=n/2, d=0;
    while(d<n){
	if(a!=n/2 && (b==n || vet[inicio+a] < vet[inicio+b])){
	    aux[d] = vet[inicio+a];
	    a++;
	}else{
	    aux[d] = vet[inicio+b];
	    b++;
	}
	d++;
    }
    for(int i=0; i<n; i++){
	vet[inicio+i] = aux[i];
    }
    return;
}

main ()
{
    int N, c, M, i, X;

    scanf("%d", &N);
    for (c=0; c<N; c++) {
	scanf("%d", &M);
	for (i=0; i<M; i++) {
	    scanf("%d", &vet[i]);
	}
	merge(0, M);
	X = 1;
	for (i=1; i<M; i++) {
	    if (vet[i] != vet[i-1]) X++;
	}
	printf("%d\n", X);
    }
}