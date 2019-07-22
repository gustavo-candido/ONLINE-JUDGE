#include <stdio.h>
main ()
{
    float N1,N2, N3, N4, media;
    scanf ("%f %f %f %f", &N1, &N2, &N3, &N4);
    media = ((N1 * 2) + (N2 * 3) + (N3 * 4) + (N4 * 1)) / (2 + 3 + 4 + 1);
    printf ("Media: %.1f\n", media);
    if ( media >= 7.0) {
    printf ("Aluno aprovado.\n");
    }
    if ( media < 5.0) {
    printf ("Aluno reprovado.\n");
    }
    if ( media >= 5.0 && media <= 6.9) {
        printf ("Aluno em exame.\n");
        float media2, media3;
        scanf("%f", &media2);
        printf ("Nota do exame: %.1f\n", media2);
        media3 = (media + media2) / 2;
        if (media3 >= 5.0) {
            printf ("Aluno aprovado.\n");
            printf ("Media final: %.1f\n", media3);
        } else if (media3 <= 4.9) {
            printf ("Aluno reprovado.\n");
            printf ("Media final: %.1f\n", media3);
        }

    }
}