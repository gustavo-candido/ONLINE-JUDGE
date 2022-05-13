#include<bits/stdc++.h>

using namespace std;

int main ()
{
	int N;
	set<int>s;
	int tmp, ant;
	
	while(scanf("%d", &N) != EOF) {
		s.clear();
		cin >> ant;
		
		for(int i=1; i<N; i++){
			cin >> tmp;
			s.insert(abs(ant-tmp));
			ant = tmp;
		}
		tmp = 0;
		ant = 1;
		for(set<int>::iterator i=s.begin(); i!=s.end(); i++, ant++){
			 if(ant == *i)tmp++;
		}
		if(tmp == N-1) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
} 
