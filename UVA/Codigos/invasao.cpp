#include <bits/stdc++.h>
using namespace std;

int C, R;
int dc[] = {0, -1, 1, 0};
int dr[] = {-1, 0, 0, 1};
vector<	vector<char> >box;

int fill (int r, int c, char c1, char c2){
	if(r < 0 || r >= R || c < 0 || c >= C) return 0;
	if(box[r][c] != c1) return 0;
	int ans = 1;
	box[r][c] = c2;
	for(int i=0; i<4; i++) {
		ans+= fill(r+dr[i], c+dc[i], c1, c2);
		
	} 
	return ans;
}

void print(){
	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			if(j != 0)printf(" ");
			if(box[i][j] != 'P') printf("#");
			else printf("F");
			
		}
		puts("");
	}
}
int main ()
{
	scanf("%d %d", &C, &R);
	getchar();
	box.resize(R);
	for(int i=0; i<R; i++) {
		box[i].resize(C);
		for(int j=0; j<C; j++) {
			scanf("%c ", &box[i][j]);
		}
	}
	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			if(box[i][j] == 'P'){box[i][j]='C'; fill(i, j, 'C', 'P');}
		}
	}
	print();
}
