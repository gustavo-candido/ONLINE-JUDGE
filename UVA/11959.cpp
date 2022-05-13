#include <bits/stdc++.h>
using namespace std;

char ans[6];
void dado(char x[], int i) {
	if(i == 0) {
		ans[0] = x[0]; ans[4] = x[4]; ans[1] = x[1]; ans[2] = x[2]; ans[3] = x[3]; ans[5] = x[5];
	}
	else if(i == 1) {
		ans[0] = x[1]; ans[4] = x[2]; ans[1] = x[0]; ans[2] = x[4]; ans[3] = x[3]; ans[5] = x[5];
	}
	else if(i == 2) {
		ans[0] = x[2]; ans[4] = x[0]; ans[1] = x[4]; ans[2] = x[1]; ans[3] = x[3]; ans[5] = x[5];
	}
	else if(i == 3) {
		ans[0] = x[3]; ans[4] = x[4]; ans[1] = x[5]; ans[2] = x[2]; ans[3] = x[1]; ans[5] = x[0];
	}
	else if(i == 4) {
		ans[0] = x[4]; ans[4] = x[1]; ans[1] = x[2]; ans[2] = x[0]; ans[3] = x[3]; ans[5] = x[5];
	}
	else if(i == 5) {
		ans[0] = x[5]; ans[4] = x[4]; ans[1] = x[3]; ans[2] = x[2]; ans[3] = x[0]; ans[5] = x[1];
	}
	ans[6] = '\0';
}

void dado_rotate(char x[]) {
	ans[0] = x[0];
	ans[1] = x[1];
	ans[2] = x[5];
	ans[3] = x[2];
	ans[4] = x[3];
	ans[5] = x[4];
}

int main()
{
	int t;
	char a[6], b[6], aux1[6], aux2[6];
	bool f;
	scanf("%d", &t);
	getchar();
	while(t--) {
		f  = false;
		scanf("%s %s", a, b);
		for(int k=0; k<4; k++) {
			for(int i=0; i<6; i++) {
				dado(a, i);
				strcpy(aux1, ans);
				for(int j=0; j<6; j++) {
					dado(b, j);
					strcpy(aux2, ans);
					if(strcmp(aux1, aux2) == 0) {
						f = true;
						i = j = k = 6;
					}
				}
			}
			dado_rotate(a);
			strcpy(a, ans);
		}
		printf("%s\n", (f)?"Equal":"Not Equal");
	}
}
