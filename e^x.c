#include <stdio.h>

int main(){
float e=1,tmp;
int x,i;

printf("\n x degerini girin ");
scanf("%d",&x);
int ust=1, alt=1;


for(i = 1; i<= x; i++){
	ust= ust * x;
	alt= alt * i;
	tmp =ust/alt;
	e = e + tmp;

	 
}

printf("\n e^%d =  %f",x,e);
return 0;
}
