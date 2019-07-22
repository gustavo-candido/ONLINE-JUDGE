#include <cstdio>

int main()
{
   int n, m;
   while(scanf("%d %d", &n, &m) && n && m)
   {
      int matriz[n][m];

      // lendo
      for(int i = 0; i < n; i++)
         for(int j = 0; j < m; j++)
            scanf("%d", &matriz[i][j]);

      // processando
      int resposta = 4, qtdUm = 0;

      for(int i = 0; i < n; i++)
      {
         for(int j = 0; j < m; j++)
         {
            if(qtdUm != -1 && matriz[i][j] == 1) // Primeira condicao, nenhuma linha com 1
               qtdUm++;
         }
         if(qtdUm == m)
         {
            resposta--;
            //printf("primeira e falha\n");
            break;
         }
         else
            qtdUm = 0;
      }
      // N = Linha M = Coluna, n competidor, m problemas
      qtdUm = 0;
      for(int j = 0; j < m; j++)
      {
         for(int i = 0; i < n; i++)
         {
            if(qtdUm != -1 && matriz[i][j] == 0) // Segunda condicao, nenhuma coluna com 0
               qtdUm++;
         }
         if(qtdUm == n)
         {
            resposta--;
           // printf("segunda eh falha\n");
            break;
         }
         else
            qtdUm = 0;
      }

      qtdUm = 0;
      for(int j = 0; j < m; j++)
      {
         for(int i = 0; i < n; i++)
         {
            if(qtdUm != -1 && matriz[i][j] == 1) // Teceira condicao, nenhuma coluna com 1
               qtdUm++;
         }
         if(qtdUm == n)
         {
            resposta--;
            //printf("terceira eh falha\n");
            break;
         }
         else
            qtdUm = 0;
      }

      qtdUm = 0;
      for(int i = 0; i < n; i++)
      {
         for(int j = 0; j < m; j++)
         {
            if(qtdUm != -1 && matriz[i][j] == 0) // Quarta condicao, nenhuma linha com 0
               qtdUm++;
         }
         if(qtdUm == m)
         {
            resposta--;
            //printf("Quarta e falha\n");
            break;
         }
         else
            qtdUm = 0;
      }

      printf("%d\n", resposta);
   }
   return 0;
}
