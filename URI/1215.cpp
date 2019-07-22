#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
main ()
{
    char text[1000], aux;
    int j=0, x=0;
    set <string> myset;
    set <string>::iterator it;
    while (scanf("%c", &aux) != EOF) {
        if ((aux < 65 || (aux > 90 && aux < 97) || aux > 122) && x==0){
            text[j] = '\0';
            myset.insert (text);
            j=0;
            x=1;
        }
        else if (aux>=65 && aux<=90) {
            text[j] = aux+32;
            j++;
            x=0;
        }
        else if (aux>=97 && aux<=122) {
            text[j] = aux;
            j++;
            x=0;
        }
    }
    for (it=myset.begin(); it!=myset.end(); it++) {
        cout << *it << endl;
    }
}
