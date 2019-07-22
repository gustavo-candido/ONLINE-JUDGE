#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 100010

int x[MAXN];
int pd[2][MAXN];

int main() {
  int n;
  while (scanf(" %d",&n) == 1 && n) {
    memset(pd,-1,sizeof(pd));
    int sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d",&x[i]); 
      sum += x[i];
    }    

    int v = 0;
    pd[v][0] = 0;
    for (int i = 0; i < n; i++) {
      int pv = v^1;
      for (int d = 0; d <= sum; d++) {
        if (pd[v][d] != -1) {
          pd[pv][d] = max(pd[pv][d],pd[v][d]);       
          pd[pv][abs(d - x[i])] = max(pd[pv][abs(d - x[i])], pd[v][d] + x[i]);                           
          pd[pv][d + x[i]] = max(pd[pv][d + x[i]], pd[v][d] + x[i]);             
        }        
      }      
      v = pv;
    }
    printf("%d\n",pd[n&1][0]/2);    
  }  
  return 0;
}
