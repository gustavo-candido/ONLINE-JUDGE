#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char line[1003], *str;
    vector<string> vet;

    cin >> n;
    cin.ignore();

    while(n--) {
        vet.clear();
        scanf("%[^\n]", line); getchar();
        for(str = strtok(line, " "); str; str = strtok(NULL, " ")) {
            vet.push_back(str);
        }
        int sz = vet.size();

        for(int i=0; i<sz; i++) {
            for(int j=0; j<sz-1; j++) {
                if(vet[j].size() < vet[j+1].size()) {
                    swap(vet[j], vet[j+1]);
                }
            }
        }
        
        int f=0;
        for(int i=0; i<sz; i++) {
            if(f) cout << " ";
            cout << vet[i];
            f=1;
        }
        cout << "\n";
    }
}