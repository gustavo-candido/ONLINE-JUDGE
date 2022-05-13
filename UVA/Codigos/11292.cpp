#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int n, m, head[20050], knight[20050], tot;
	
	while(scanf("%d %d", &n, &m) && n && m) {
		tot=0;
		for(int i=0; i<n; i++) scanf("%d", &head[i]);
		for(int i=0; i<m; i++) scanf("%d", &knight[i]);
		sort(head,head+n);
		sort(knight, knight+m);
		int i=0, j=0;
		while(i<n && j<m) {
			if(head[i] > knight[j])j++;
			else {tot+=knight[j]; i++;j++;}
		}
		if(i == n) printf("%d\n",tot);
		else printf("Loowater is doomed!\n");
	} 
}
