#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Cikarma(int A,int B);
int Carpma(int A,int B);
int Bolme(int A,int B);
int Toplama(int A,int B);
int Mod(int A,int B);
int Power(int A,int B);
void islemMenuPrint(void);


void main(){
	printf("HESAP MAKINESI\n\n");
	int q=0;
	do{
		
	}while(q=0);
	
	
	
	
}

Void islemMenuPrint(void){
	int func;
	printf("ISLEMINIZI SECIN\n");
	printf("ISLEMLER\n");
	printf(" 1)Toplama\n 2)Cikarma \n 3)Carpma \n 4)Bolme \n 5)Mod \n 6)Power \n\n");
	scanf("%d",%func);
	
}



int Carpma(int A,int B){
	int tmp;
	tmp = A*B;
	return tmp;
}
int Bolme(int A,int B){
	int tmp;
	if(B == 0){
	printf("sifira bolum yapılamaz \ntekrar deneyin");
	return	NULL;
	}
	else{
	tmp = A/B;
	return tmp;}
}
int Toplama(int A,int B){
	int tmp;
	tmp = A+B;
	return tmp;
} 
int Cikarma(int A,int B){
	int tmp;
	tmp = A-B;
	return tmp;
}
int Mod(int A,int B){
	int tmp;
	if(B == 0){
	printf("sifira bolum yapılamaz \ntekrar deneyin");
	return	NULL;
	}
	else{
	tmp = A%B;
	return tmp;}
}
int Power(int A,int B){	
	int tmp =1;	
	if(B != 0){
	int i;
	for(i=0;i<B;i++)
		tmp = tmp * A;
	}
	return tmp;
}


/*

	int tmp;
	
	return tmp;