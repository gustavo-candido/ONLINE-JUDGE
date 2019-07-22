#include <stdio.h>
#include <vector>
using namespace std;

main ()
{
    vector<char> myvector;
    vector<char>:: iterator it;
    int A, B;
    char x;

    while (scanf("%d %d", &A, &B)) {
        if (A == 0 && B == 0) break;
        getchar();
        while(scanf("%c", &x)) {
            if (x == '\n') break;
            while (!myvector.empty() && x > myvector.back() && B > 0) {
                myvector.pop_back();
                B--;
            }
            myvector.push_back(x);
        }
        while (B > 0) {
            x = myvector.back()+1;
            while (!myvector.empty() && x > myvector.back() && B > 0) {
                myvector.pop_back();
                B--;
            }
            x++;
        }
        for (it = myvector.begin(); it != myvector.end(); it++) {
            printf("%c", *it);
            if (it+1 == myvector.end()) printf("\n");
        }
        myvector.clear();
    }
}