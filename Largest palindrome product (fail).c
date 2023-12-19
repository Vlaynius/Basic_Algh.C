#include <stdio.h>					//Largest palindrome product

int Mostsignum(int sum);
int Leastsignum(int sum);

int main(){
	
	int sum, msn ,lsn;
	int check = 0;
	int n1=999, n2=999;
while(check = 1){
	
	sum = n1 * n2 ;
	msn = Mostsignum(sum);
	lsn = Leastsignum(sum);
	if(msn == lsn){
		check = 1;
	}else
	{
		n1--;	//n1--
		n2--;	//n2--
	}
}
printf("\n Largest polinrome number in 3 digits is %d",sum);
printf("\n\n %d  x  %d  ",n1 ,n2);

return 0;
}

int Mostsignum(int sum){			//Most significant bit finder
	int msn, x;
	x = sum;
	while(x > 9){	
		x = x / 10; 
	}
	
	return msn;
}


int Leastsignum( int sum )  {			//Least significant bit finder
	int lsn;
	lsn = sum % 10;
	
	return lsn;
}

