#include <stdio.h>
#include <string.h>

int main ()
{
    char text[100];
    int i, tam, x, y;

    while (gets(text) != NULL) {
            tam = strlen(text);
            x=0;
            y=0;
            for (i=0; i<tam; i++) {
                if (x==0 && text[i] == '*') {
                    printf("<b>");
                    x=1;
                }
                else if (x==1 && text[i] == '*') {
                    printf("</b>");
                    x=0;
                }
                else if (y==0 && text[i] == '_') {
                    printf("<i>");
                    y=1;
                }
                else if (y==1 && text[i] == '_') {
                    printf("</i>");
                    y=0;
                }
                else printf("%c", text[i]);
            }
            printf("\n");
    }
    return 0;
}