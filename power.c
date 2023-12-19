#include <stdio.h>  // a^b

int main(){
	int a, b;
	int toplam = 1;
	printf("\n alt ve ustu giriniz = ");
	
	scanf("%d %d",&a,&b);
	for(int i=1; i <= b; i++){
		
		toplam = toplam*a;
	}
	
	printf("\n cevap =  %d",toplam);
	return 0;
	
}
