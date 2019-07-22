#include <stdio.h>

int main ()
{
	int vet[100], x=0, maior= -100;
	
	for (int i=0; i<100; i++) {
		scanf("%d", &vet[i]);
		if (vet[i] > maior) {
			maior = vet[i];
			x = i+1;
		}
	}
	printf("%d\n%d\n", maior, x);
	
}
