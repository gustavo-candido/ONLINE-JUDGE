#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, freq[30];
  char plan[30], a[30], b[30];
  bool f;


  scanf("%d", &t);
  getchar();

  while(t--) {
    memset(freq, 0, sizeof freq);
    gets(plan);
    gets(a);
    gets(b);
    f = true;
    for(int i=0; i<(int)strlen(plan); i++) freq[plan[i]-'A']++;
    for(int i=0; i<(int)strlen(a); i++) {
        if(!f) break;
        freq[a[i]-'A']--;
        if(freq[a[i]-'A'] < 0) f = false;
    }
    for(int i=0; i<(int)strlen(b); i++) {
        if(!f) break;
        freq[b[i]-'A']--;
        if(freq[b[i]-'A'] < 0) f = false;
    }
    if(!f) puts("CHEATER");
    else {
        for(int i=0; i<27; i++) {
            if(freq[i]) {
                printf("%c", i+'A');
            }
        }
        puts("");
    }
  }
}
