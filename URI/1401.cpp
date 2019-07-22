#include <stdio.h>
#include <string.h>
#include <algorithm>

bool compare (char A, char B) {
    if (A > B) return false;
    else return true;
}

int main ()
{
    int N, end;
    char X[15];
    scanf("%d ", &N);

    for (int i=0; i<N; i++) {
        gets(X);
        end = strlen(X);
        std::stable_sort(&X[0], &X[end], compare);
        do {
            puts(X);
        }
        while (std::next_permutation(X,X+end));
        printf("\n");
    }
}
