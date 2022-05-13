#include <bits/stdc++.h>

int main ()
{
	bool sol = false; 
	int x, y, z, A, B, C, N;
	
	std::cin >> N;
	
	while(N--) {
		std::cin >> A >> B >> C;
		sol = false;
		for (x = -22; x <= 22 && !sol; x++) if (x * x <= C)
			for (y = -100; y <= 100 && !sol; y++) if (y != x && x * x + y * y <= C)
				for (z = -100; z <= 100 && !sol; z++)
					if (z != x && z != y && x + y + z == A && x * y * z == B && x * x + y * y + z * z == C) {
						printf("%d %d %d\n", x, y, z);
					sol = true;
				}
		
		if(!sol) printf("No solution.\n");
	}
}
