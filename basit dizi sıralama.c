#include <stdio.h>

int main(){
int dizi1[6] = {2,6,9,10,12,15};
int dizi2[4] = {1,3,5,7};
int dizi3[10];
int i=0,j=0,k;


while(i<6 || j<4)
{
	k = i + j;
	if(dizi1[i]<dizi2[j]){
		dizi3[k]=dizi1[i];
		i++;
	}
		else 
		{
		dizi3[k]= dizi2[j];
		j++;
		}
	}

for(k=0; k<10; k++){
	printf("%d",dizi3[k]);
	
}

return 0;}
