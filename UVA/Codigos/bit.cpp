#include <bits/stdc++.h>

int main ()
{
	int bit = 0, aux;
	
	while(1) {
		scanf("%d", &aux);
		
		if (aux == 1) {
			printf("Insira valor: ");
			scanf("%d", &aux);
			bit = bit | aux << 1;
			printf("%d inserido\n", aux);
		}
		else if (aux == 2) {
			printf("Pesquise valor: ");
			scanf("%d", &aux);
			if (bit & (1 << aux)) printf("%d existe\n", aux);
			else printf("%d n existe\n", aux);
			
		}
		
	}
}
