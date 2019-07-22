#include <stdio.h>
#include <string.h>

main ()
{
    char A[100000];
    int i;
    while (scanf("%[^\n]", &A) != EOF) {
        for (i=0; i<strlen(A); i++) {
            if (A[i] == '1') {
                A[i] = '`';
            }
            else if (A[i] == '2') {
                A[i] = '1';
            }
            else if (A[i] == '3') {
                A[i] = '2';
            }
            else if (A[i] == '4') {
                A[i] = '3';
            }
            else if (A[i] == '5') {
                A[i] = '4';
            }
            else if (A[i] == '6') {
                A[i] = '5';
            }
            else if (A[i] == '7') {
                A[i] = '6';
            }
            else if (A[i] == '8') {
                A[i] = '7';
            }
            else if (A[i] == '9') {
                A[i] = '8';
            }
            else if (A[i] == '0') {
                A[i] = '9';
            }
            else if (A[i] == '-') {
                A[i] = '0';
            }
            else if (A[i] == '=') {
                A[i] = '-';
            }
            else if (A[i] == 'W') {
                A[i] = 'Q';
            }
            else if (A[i] == 'E') {
                A[i] = 'W';
            }
            else if (A[i] == 'R') {
                A[i] = 'E';
            }
            else if (A[i] == 'T') {
                A[i] = 'R';
            }
            else if (A[i] == 'Y') {
                A[i] = 'T';
            }
            else if (A[i] == 'U') {
                A[i] = 'Y';
            }
            else if (A[i] == 'I') {
                A[i] = 'U';
            }
            else if (A[i] == 'O') {
                A[i] = 'I';
            }
            else if (A[i] == 'P') {
                A[i] = 'O';
            }
            else if (A[i] == '[') {
                A[i] = 'P';
            }
            else if (A[i] == ']') {
                A[i] = '[';
            }
            else if (A[i] == '\\') {
                A[i] = ']';
            }
            else if (A[i] == 'S') {
                A[i] = 'A';
            }
            else if (A[i] == 'D') {
                A[i] = 'S';
            }
            else if (A[i] == 'F') {
                A[i] = 'D';
            }
            else if (A[i] == 'G') {
                A[i] = 'F';
            }
            else if (A[i] == 'H') {
                A[i] = 'G';
            }
            else if (A[i] == 'J') {
                A[i] = 'H';
            }
            else if (A[i] == 'K') {
                A[i] = 'J';
            }
            else if (A[i] == 'L') {
                A[i] = 'K';
            }
            else if (A[i] == ';') {
                A[i] = 'L';
            }
            else if (A[i] == '\'') {
                A[i] = ';';
            }
            else if (A[i] == 'X') {
                A[i] = 'Z';
            }
            else if (A[i] == 'C') {
                A[i] = 'X';
            }
            else if (A[i] == 'V') {
                A[i] = 'C';
            }
            else if (A[i] == 'B') {
                A[i] = 'V';
            }
            else if (A[i] == 'N') {
                A[i] = 'B';
            }
            else if (A[i] == 'M') {
                A[i] = 'N';
            }
            else if (A[i] == ',') {
                A[i] = 'M';
            }
            else if (A[i] == '.') {
                A[i] = ',';
            }
            else if (A[i] == '/') {
                A[i] = '.';
            }
        }
        printf("%s\n", A);
        getchar();
    }
}
