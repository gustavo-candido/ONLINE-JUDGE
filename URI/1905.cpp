#include <iostream>
using namespace std;

int grid[6][6];

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

bool Search(int r, int c) {
    if(r < 0 || r >= 5 || c < 0 || c >= 5 || grid[r][c] == 1) return false;
    if(r == 4 && c == 4) return true;

    bool ans = false;
    int aux = grid[r][c];
    grid[r][c] = 1;

    for(int i=0; i<4; i++) {
       ans = Search(r+dr[i], c+dc[i]);
        if(ans) break;
    }
    grid[r][c] = aux;
    return ans;
}

int main()
{
    int n;

    cin >> n;

    while(n--) {
        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++) cin >> grid[i][j];
        if(Search(0,0)) cout << "COPS\n";
        else cout << "ROBBERS\n";
    }
}
