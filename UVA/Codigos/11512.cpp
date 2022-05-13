#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1010

char T[MAX_N],  P[MAX_N];

int SA[MAX_N], LCP[MAX_N], i, n, m, ans, sub, b[MAX_N];

bool cmp(int a, int b) { return strcmp(T + a, T + b) < 0; }

void computeLCP_slow() {
	LCP[0] = 0;
	for (int i = 1; i < n; i++) {
		int L = 0;
		while (T[SA[i] + L] == T[SA[i-1] + L]) L++;
		LCP[i] = L;
	} 
}

void maximu_lcp ()
{
	ans = sub = -1;
	for(int j=0; j<n; j++) {
		if(ans < LCP[j]) {
			ans = LCP[j];
			sub = SA[j];
		}
	}
}

void kmpPreprocess() {
	int i = 0, j = -1; b[0] = -1;
	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = b[j];
		 i++;j++; 
		 b[i] = j;
	} 
}

void kmpSearch() {
int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && T[i] != P[j]) j = b[j]; 
		i++; j++;
		if (j == m) {
			//printf("P is found at index %d in T\n", i - j);
			j = b[j];
			ans++;
		}
	}
}

int main() {
	int N;
	
	cin >> N;
	getchar();
	while(N--) {
		n = (int)strlen(gets(T)); 
		for (int i = 0; i < n; i++) SA[i] = i; 
		sort(SA, SA + n, cmp);
		computeLCP_slow();
		maximu_lcp();
		for(int i=sub, j=0; j<ans; i++, j++) {
			P[j] = T[i];
		} 
		P[ans] = '\0';
		m = (int)strlen(P);
		ans = 0;
		kmpPreprocess();
		kmpSearch();
	
		if(m != 0){cout << P << " " << ans << endl;}
		else printf("No repetitions found!\n");
	}
	
} 

/*
 * 
 *WA
 * #include <bits/stdc++.h>
#define MAXI 1000000
using namespace std;

char T[MAXI], P[MAXI];
int tam, SA[MAXI], LCP[MAXI],b[MAXI], sub, ans;

bool cmp(int a, int b){ return strcmp(T+a, T+b) < 0;}

void compute_lcs() {
	LCP[0] = 0;
	ans = -1;
	sub = -1;
	for(int i=1; i<tam; i++) {
		int L=0;
		while(T[SA[i]+L] == T[SA[i-1]+L])L++;
		LCP[i] = L;
	}
}
void maximu_lcs() {
	ans = sub = -1;
	for(int i=0; i<tam; i++) {
		if(ans < LCP[i]) {
			ans = LCP[i];
			sub = SA[i];
		}
	}
	
}
void kmpPreprocess() {
	int i = 0, j = -1; b[0] = -1;
	while (i < strlen(P)) {
		while (j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	} 
}
void kmpSearch() {
	int i = 0, j = 0;

	while (i < tam) {
		while (j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		if (j == strlen(P)) {
			j = b[j];
			ans++;
		} 
	}
}


int main()
{
	int N;
	
	cin >> N;
	getchar();
	
	while(N--) {
		tam = strlen(gets(T));
		for(int i=0; i<tam; i++) SA[i] = i;
		sort(SA, SA+tam, cmp);
		compute_lcs();
		maximu_lcs();
		for(int i=sub, j=0;j<ans; j++, i++) P[j] = T[i];
		P[ans] = '\0';
		ans = 0;
		kmpPreprocess();
		kmpSearch();
		if(strlen(P) != 0)printf("%s %d\n", P,ans);
		else printf("No repetitions found!\n");
	}
}
*/
