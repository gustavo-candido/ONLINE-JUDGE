#include <bits/stdc++.h>
using namespace std;

char dir (char pos, char ins) {
	if(pos == 'N' && ins == 'E') pos = 'O';
	else if(pos == 'N' && ins == 'D') pos = 'L';
	
	else if(pos == 'S' && ins == 'E') pos = 'L';
	else if(pos == 'S' && ins == 'D') pos = 'O';
	
	else if(pos == 'L' && ins == 'E') pos = 'N';
	else if(pos == 'L' && ins == 'D') pos = 'S';
	
	else if(pos == 'O' && ins == 'E') pos = 'S';
	else if(pos == 'O' && ins == 'D') pos = 'N';
	
	return pos;
}

int main ()
{
	char box[1000][1000];
	int N, M, S, x, y, count;
	char pos, ins;
	while(cin >> N >> M >> S && N && M && S) {
		getchar();
		count=0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				scanf("%c", &box[i][j]);
				if(box[i][j] == 'N' || box[i][j] == 'S' || box[i][j] == 'L' || box[i][j] == 'O') {x=i;y=j;pos = box[i][j];}
			}
			getchar();
		}
		
		for(int i=0; i<S; i++) {
			scanf("%c", &ins);
			if(ins == 'F') {
				if(pos == 'N' && box[x-1][y] != '#' && x-1 >= 0) x--;
				else if(pos == 'S' && box[x+1][y] != '#' && x+1 < N) x++;
				else if(pos == 'L' && box[x][y+1] != '#' && y+1 < M) y++;
				else if(pos == 'O' && box[x][y-1] != '#' && y-1 >= 0) y--;
			}
			else pos = dir(pos, ins);
			if(box[x][y] == '*') {
				box[x][y] = '.';
				count++;
			}
		}
		printf("%d\n", count);
	}
}
