#include<stdio.h>

main(){


int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0;
double n;

scanf("%lf",&n);

while(n>=100){

    a++;
    n=n-100;

}
while(n>=50){

    b++;
    n=n-50;

}
while(n>=20){

    c++;
    n=n-20;

}
while(n>=10){

    d++;
    n=n-10;

}
while(n>=5){

    e++;
    n=n-5;

}
while(n>=2){

    f++;
    n=n-2;

}
while(n>=1){

    g++;
    n=n-1;

}

while(n>=0.5){
    h++;
    n=n-0.5;

}
while(n>=0.25){
    i++;
    n=n-0.25;

}

while(n>=0.10){
    j++;
    n=n-0.10;

}

while(n>=0.05){
    k++;
    n=n-0.05;

}

while(n>=0.01){
    l++;
    n=n-0.01;

}


printf("NOTAS:\n");
printf("%d nota(s) de R$ 100.00\n",a);
printf("%d nota(s) de R$ 50.00\n",b);
printf("%d nota(s) de R$ 20.00\n",c);
printf("%d nota(s) de R$ 10.00\n",d);
printf("%d nota(s) de R$ 5.00\n",e);
printf("%d nota(s) de R$ 2.00\n",f);

printf("MOEDAS:\n");
printf("%d moeda(s) de R$ 1.00\n",g);
printf("%d moeda(s) de R$ 0.50\n",h);
printf("%d moeda(s) de R$ 0.25\n",i);
printf("%d moeda(s) de R$ 0.10\n",j);
printf("%d moeda(s) de R$ 0.05\n",k);
printf("%d moeda(s) de R$ 0.01\n",l);

return 0;
}
