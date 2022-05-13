#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int N, NC=0;
	vector<int>set;
	while(cin >> N) {
		if(!N) break;
		if(NC) cout << endl;
		set.reserve(N);
		for(int i=0; i<N; i++) {
			cin >> set[i];
		}
		for (int a = 0; a < N - 5; a++)	// six nested loops!
			for (int b = a + 1; b < N - 4; b++)
				for (int c = b + 1; c < N - 3; c++)
					for (int d = c + 1; d < N - 2; d++)
						for (int e = d + 1; e < N - 1; e++)
							for (int f = e + 1; f < N; f++) 
								printf("%d %d %d %d %d %d\n",set[a],set[b],set[c],set[d],set[e],set[f]);
		NC=1;
	}
}
