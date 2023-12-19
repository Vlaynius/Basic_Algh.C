#include <stdio.h>

void printinbinary(int n);

int main()
{
	int n;
	printf("decimal to binary converter \n \n please enter a number =  ");
	scanf("%d",& n);
	
	printinbinary(n);
	
	return 0;
}


void printinbinary(int n){
	
	if ( n < 2){
		
		printf("%d",n);
		
	}else {	
		
		printinbinary(n/2);
		
		printinbinary(n%2);
		
	}
}
