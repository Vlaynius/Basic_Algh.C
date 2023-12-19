#include <stdio.h>

int main()
{
	char tmp;
	char repeat = 'E';
	do{															// Input
	printf("\nKelimeyi girin = ");
	char str[20];
	scanf("%[^\n]%*c", str);
	char ilkharf = str[0];
		
		do{
			printf("%s \n",str);
			tmp = str[0];
			int i=0;
			
				do{													//Kaydirma
					
					str[i] = str[i+1];
					i++;
					
				}
				while(str[i] != '\0' );
				
			str[i] = tmp;											//ilk harfi sona yazdýrma
		}
		while(ilkharf != str[0]);
		
	printf("\n tekrar icin e yaziniz = ");						//Tekrar Kontrol
	scanf("%c",&repeat);
	}
	while(repeat == 'e' || repeat == 'E');
	
	return 0;
}
