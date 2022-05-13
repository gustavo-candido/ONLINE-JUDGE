#include <bits/stdc++.h>
#define mp make_pair
#define ft first
#define sd second
#define ll long long 
#define ue printf("what?\n");
#define pb push_back
#define oo 0x3F3F3F3F
#define maxn 100

using namespace std;

int ciclo, n, v[60];
int g[60][60];
double rsp;

void bt(int at, int vis, int peso)
{
	if((peso*1.)/((vis+1)*1.) > rsp)
		return;
	for(int i=0; i<n; i++)
	{
		if(g[at][i] != oo)
		{
			if(i == ciclo)
			{
				rsp = min(rsp,((peso+g[at][i])*1.)/(vis*1.));
				return;
			}
			bool found = 0;
			for(int j=0; j<vis; j++)
				if(v[j] == i)
				{
					found = 1;
					break;
				}
			if(found)
				continue;
			
			v[vis] = i;
			bt(i,vis+1,peso+g[at][i]);
		}
	}
}

main()
{
	int t, caso, m, i, j, A, B;
	int peso;
	scanf("%d", &t);
	caso = 1;
	while(t--)
	{
		scanf("%d%d", &n, &m);
		
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				g[i][j] = oo;
		
		
		while(m--)
		{
			scanf("%d%d%d", &A, &B, &peso);
			A--; B--;
			g[A][B] = min(g[A][B],peso);
		}

		
		rsp = 1000000000000.0;
		
		for(i=0; i<n; i++)
		{
			ciclo = i;
			v[0] = i;
			bt(i, 1, 0);
		}
		
		printf("Case #%d: ", caso++);
		if(rsp == 1000000000000.0)
			printf("No cycle found.\n");
		else
			printf("%.2lf\n", rsp);
	}
}
		
			
		
