#include <stdio.h>
#include <string.h>
 
main ()
{
    char A[10000];
 
    while (scanf("%s", A) != EOF) {
        if (strcmp (A, "brasil") == 0) printf("Feliz Natal!\n");
        else if (strcmp (A, "alemanha") == 0) printf("Frohliche Weihnachten!\n");
        else if (strcmp (A, "austria") == 0) printf("Frohe Weihnacht!\n");
        else if (strcmp (A, "coreia") == 0) printf("Chuk Sung Tan!\n");
        else if (strcmp (A, "espanha") == 0) printf("Feliz Navidad!\n");
        else if (strcmp (A, "grecia") == 0) printf("Kala Christougena!\n");
        else if (strcmp (A, "estados-unidos") == 0) printf("Merry Christmas!\n");
        else if (strcmp (A, "inglaterra") == 0) printf("Merry Christmas!\n");
        else if (strcmp (A, "australia") == 0) printf("Merry Christmas!\n");
        else if (strcmp (A, "portugal") == 0) printf("Feliz Natal!\n");
        else if (strcmp (A, "suecia") == 0) printf("God Jul!\n");
        else if (strcmp (A, "turquia") == 0) printf("Mutlu Noeller\n");
        else if (strcmp (A, "argentina") == 0) printf("Feliz Navidad!\n");
        else if (strcmp (A, "chile") == 0) printf("Feliz Navidad!\n");
        else if (strcmp (A, "mexico") == 0) printf("Feliz Navidad!\n");
        else if (strcmp (A, "antardida") == 0) printf("Merry Christmas!\n");
        else if (strcmp (A, "canada") == 0) printf("Merry Christmas!\n");
        else if (strcmp (A, "irlanda") == 0) printf("Nollaig Shona Dhuit!\n");
        else if (strcmp (A, "belgica") == 0) printf("Zalig Kerstfeest!\n");
        else if (strcmp (A, "italia") == 0) printf("Buon Natale!\n");
        else if (strcmp (A, "libia") == 0) printf("Buon Natale!\n");
        else if (strcmp (A, "siria") == 0) printf("Milad Mubarak!\n");
        else if (strcmp (A, "marrocos") == 0) printf("Milad Mubarak!\n");
        else if (strcmp (A, "japao") == 0) printf("Merii Kurisumasu!\n");
        else printf("--- NOT FOUND ---\n");
    }
}