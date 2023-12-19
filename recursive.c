#include <stdio.h>

int power(int x, int exp);
void printinbinary(int n);
int fibonacci(int n);

void main(void)
{
		
}


int power(int x,int exp){
	
	if (exp == 0 ){
		return 1;
	}
	else {
		return x * power(x, exp-1);
	}
}

void printinbinary(int n){
	if(n<2){
		printf("%d ",n);
	}else{
		
		printinbinary(n/2);
		printinbinary(n%2);
		}
	}
	
int fibonacci(int n){
	if(n<=1){
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}	
