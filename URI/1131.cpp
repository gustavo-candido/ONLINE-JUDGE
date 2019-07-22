#include <stdio.h>
main ()
{
    int P=1, I, G, GREN=1, gremio=0, inter=0, empi=0;
    while (1) {
        scanf("%d %d", &I, &G);
        if (I>G) {
            inter++;
        }
        if (G>I) {
            gremio++;
        }
        if (G==I) {
            empi++;
        }
    printf("Novo grenal (1-sim 2-nao)\n");
    scanf("%d", &P);
    if (P!=1 && P!=2) {
    while (P!=1 && P!=2) {
        scanf ("%d");
    } }
    if (P==1) {
        GREN++;
    }
    if (P==2) {
        break;
    }
    }
    printf("%d grenais\n", GREN);
    printf("Inter:%d\n", inter);
    printf("Gremio:%d\n", gremio);
    printf("Empates:%d\n", empi);
    if (inter>gremio) {
        printf ("Inter venceu mais\n");
    }
    if (gremio>inter) {
        printf ("Gremio venceu mais\n");
    }
    if (gremio==inter) {
        printf ("Nao houve vencedor\n");
    }
}