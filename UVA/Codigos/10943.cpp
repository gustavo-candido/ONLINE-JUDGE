#include <cstdio>
#include <cstring>
using namespace std;

 int dp[110][110], N, K;

int main() {
 
  memset(dp, 0, sizeof dp);

  for (int i=0; i<=100; i++) 
    dp[i][1]=1;
	
  for (int j=1; j<=100; j++) {
    for (int i=0; i<=100; i++){
      for (int split=0; split<=100-i; split++) {
        dp[i + split][j + 1] += dp[i][j];
        dp[i + split][j + 1] %= 1000000;
      }
	}
  }
  while (scanf("%d %d", &N, &K), (N || K)) printf("%d\n", dp[N][K]);

  return 0;
}
