# include <stdio.h>
# include <stdlib.h>

typedef struct _Pilha
{
    char op;
    struct _Pilha *prox;
}Pilha;

void transfereTempPos( Pilha **pPos, Pilha **pTemp, Pilha *aux )
{
    aux = ( *pTemp ) -> prox;
    ( *pTemp ) -> prox = *pPos;
    *pPos = *pTemp;
    *pTemp = aux;
}

void alocaCharNaPilha( Pilha **pilha, Pilha *aux, char op )
{
    aux = ( Pilha *) malloc( sizeof( Pilha ) );
    aux -> op = op;  
    aux -> prox = *pilha;
    *pilha = aux;
}

void leOperacao( Pilha **pPos, Pilha **pTemp )
{
    char op;
    Pilha *aux;
    
    scanf( "%c", &op );
    while( op != '\n' )
    {      

        switch( op )
        {
            case '+':
            case '-':

                while( ( *pTemp ) && ( (*pTemp) -> op != '(' ) )
                {
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                alocaCharNaPilha( &( *pTemp ), aux, op );
                
                break;

            case '*':
            case '/':

                while( ( *pTemp ) && ( (*pTemp) -> op != '+' && (*pTemp) -> op != '-'
                        && (*pTemp) -> op != '(' ) )
                {        
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                alocaCharNaPilha( &( *pTemp ), aux, op );
                
                break;
               
            case '^':

                while( ( *pTemp ) && ( (*pTemp) -> op != '+' && (*pTemp) -> op != '-' && (*pTemp) -> op != '*' && (*pTemp) -> op != '/' && (*pTemp) -> op != '(' )) {        
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                alocaCharNaPilha( &( *pTemp ), aux, op );
                
                break;

            case ')':
                while( ( *pTemp ) && ( (*pTemp) -> op != '(' ) )
                {
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                if( (*pTemp) && (*pTemp) -> op == '(' )
                {
                    aux = *pTemp;
                    *pTemp = (*pTemp) -> prox;
                    free( aux );
                }
                
                break;

            case '(':
                alocaCharNaPilha( &( *pTemp ), aux, op );
                
                break;

            default:
                alocaCharNaPilha( &( *pPos ), aux, op );
                
                break;
        }

        scanf( "%c", &op );
    }

    while( *pTemp ){
		transfereTempPos( &( *pPos ), &( *pTemp ), aux );
	}

    
}

void imprime( Pilha *topo )
{
    if( topo )
    {
        imprime( topo -> prox );
        printf( "%c", topo -> op );
    }   
}

main()
{
	int N, c;
	scanf("%d ",&N);
	for (c=0; c<N; c++) {
		Pilha *pPos = NULL;
		Pilha *pTemp = NULL;
		leOperacao( &pPos, &pTemp );
		imprime( pPos );
		printf("\n");
	}
}