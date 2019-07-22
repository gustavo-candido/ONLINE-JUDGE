#include<bits/stdc++.h>
using namespace std;

typedef struct ren
{
	char nome[1000];
	double atl;
	int peso, idade;
} rena;

bool cmp(rena a, rena b)
{
	if (a.peso > b.peso) return true;
	else if (a.peso < b.peso) return false;
	else
	{
		if (a.idade < b.idade) return true;
		else if (a.idade > b.idade) return false;
		else
		{
			if (a.atl < b.atl) return true;
			else if (a.atl > b.atl) return false;
			else
			{
				if (strcmp(a.nome, b.nome) < 0) return true;
				else if (strcmp(a.nome, b.nome) > 0) return false;
				else return false;
			}
		}
	}
}

int main()
{
	int t, z = 0;
	cin >> t;
	while (t--)
	{
		int n, nc;
		cin >> n >> nc;
		rena treno[1000];
		for (int i = 0; i < n; i++)
		{
			cin >> treno[i].nome >> treno[i].peso >> treno[i].idade >> treno[i].atl; 
		}
		sort(treno, treno + n, cmp);
		printf("CENARIO {%d}\n", ++z);
		for (int i = 0; i < nc; i++)
		{
			printf("%d - %s\n", i + 1, treno[i].nome);
		}
	}
}