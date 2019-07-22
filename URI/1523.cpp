#include <stdio.h>
#include <stdlib.h>
#include <stack>
 
using namespace std;
 
struct car{
    int ent, sai;  
};
 
int main(){
        int a, b, c, N, C;
        struct car *V, aux, aux2;
        stack <struct car> pilha;
        bool T = false;
        while (scanf("%d %d", &C, &N)){
            if(!N && !C) break;
            V = (struct car*) malloc(C*sizeof(struct car));
            for(a=0; a<C; a++) scanf("%d %d", &V[a].ent, &V[a].sai);
            //pilha.push(-1);
            T = true;
            for(a=0; a<C; a++){
                if(pilha.empty()) pilha.push(V[a]);else
                {
                    aux = pilha.top();
                    if(V[a].sai < aux.sai) {
                        if(pilha.size() > N){
                            T = false;
                            break;
                        }else pilha.push(V[a]);
                    }else
                    if(V[a].sai > aux.sai){
                        if(V[a].ent >= aux.sai) {
                            while(V[a].ent >= aux.sai && !pilha.empty()){
                                pilha.pop();
                                if(!pilha.empty()) aux = pilha.top();
                            }
                            if(pilha.size() > N){
                                T = false;
                                break;
                            }else pilha.push(V[a]);
                        }else{
                            T = false;
                            break;
                        }
                    }
                }
            }
            while(pilha.size() > 1){
                aux = pilha.top();
                pilha.pop();
                aux2 = pilha.top();
                if(aux.sai > aux2.sai) {
                    T = false;
                    break;
                }
            }
            if(T) printf("Sim\n");else printf("Nao\n");
            while(!pilha.empty()) pilha.pop();
            free(V);
        }
}
