#include <stdio.h>
#include <string.h>

int main ()
{
    int N, hori[9], box[9][9];
    bool inst;

    scanf("%d", &N);
    for(int c=0; c<N; c++) {
        inst = true;
        memset(hori, 0, sizeof(int) * 9);
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                scanf("%d", &box[i][j]);
                hori[box[i][j]-1]++;
            }
            if (inst==true) {
                for (int j=0; j<9; j++) {
                    if (hori[j]==0) {
                            inst = false;
                            break;
                    }
                }
            }
            memset(hori, 0, sizeof(int) * 9);
        }
        if (inst==true) {
            for (int i=0; i<9; i++) {
                for (int j=0; j<9; j++) {
                    hori[box[j][i]-1]++;
                }
                for (int j=0; j<9; j++) {
                    if (hori[j]==0) {
                            inst = false;
                            break;
                    }
                }
                if (inst == false)break;
                memset(hori, 0, sizeof(int) * 9);
            }
        }
        if (inst==true) {
                int x=0, y;
            for (int X=0; X<3; X++) {
                    y=0;
                for (int Y=0; Y<3; Y++) {
                    for (int i=x; i<x+3; i++) {
                        for (int j=y; j<y+3; j++) {
                            hori[box[i][j]-1]++;
                        }
                    }
                    for (int j=0; j<9; j++) {
                        if (hori[j]==0) {
                                inst = false;
                                break;
                        }
                    }
                    if (inst == false) break;
                    memset(hori, 0, sizeof(int) * 9);
                    y+=3;
                }
                if (inst==false) break;
                x+=3;
            }
        }
        printf("Instancia %d\n", c+1);
        if (inst == true) printf("SIM\n\n");
        else printf("NAO\n\n");
    }
}
