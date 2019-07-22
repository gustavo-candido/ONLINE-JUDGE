#include <stdio.h>

main ()

{
  int N, a, b, c, d, e, f, g;
  scanf("%d", &N);
  printf("%d\n", N);
  a = N/100;
  printf("%d nota(s) de R$ 100,00\n", a);
  b = (N-a*100)/50;
  printf("%d nota(s) de R$ 50,00\n", b);
  c = (N-a*100-b*50)/20;
  printf("%d nota(s) de R$ 20,00\n", c);
  d = (N-a*100-b*50-c*20)/10;
  printf("%d nota(s) de R$ 10,00\n", d);
  e = (N-a*100-b*50-c*20-d*10)/5;
  printf("%d nota(s) de R$ 5,00\n", e);
  f = (N-a*100-b*50-c*20-d*10-e*5)/2;
  printf("%d nota(s) de R$ 2,00\n", f);
  g = (N-a*100-b*50-c*20-d*10-e*5-f*2)/1;
  printf("%d nota(s) de R$ 1,00\n", g);
}
