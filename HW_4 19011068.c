//Harfin sekans için seçilip seçilmediði bilgisini de saklayan ek bir matris oluþturulmalýdýr.
//birden fazla lcs varsa hepsi ekrana yazdýrýlmalý

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGSIZE 50	//Max string size 50 atandý.


//Girilen iki integer deðerden büyük olanýný döndüren fonksiyon.
int max(int a, int b) {
    if(a>b){
   	   	  return a;	//* int a, int b'den büyükse a dündürülür.
	}else return b;	//* int b büyükse veya iki sayý eþitse b döndürülür. 
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int columns) {
	int i,j;
	for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

// En uzun ortak sekansý bulan ve boyutunu döndüren fonksiyon.
void findLongestCommonSequence(char *str1, char *str2) {
    //Oluþturucaðýmýz çözüm matrisinin boyutlarý için kullanacaðýmýz iki dizinin uzunlularý alýnýr.
	int m = strlen(str1);	//str1 dizisinin uzunluðu integer m'ye atanýr.
    int n = strlen(str2);	//str2 dizisinin uzunluðu integer n'ye atanýr.
	
	int i,j;
	
    // Çözüm matrisi oluþturulur. Hafýzada yer ayarlanýr.
    int **L = (int **)malloc((m + 1) * sizeof(int *));
    for ( i = 0; i <= m; i++) {
        L[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    for ( i = 0; i <= m; i++) {
   		for ( j = 0; j <= n; j++){
   			L[i][j] = 0;
		   }
	}
	//*Çözüm matrisinin ilk hali ekrana yazdýrýlýr.	
	printf("\n  <<Cozum Matrisinin ilk hali>>\n");
	
    // Ýç içe iki for döngüsü ile çözüm matrisi doldurulur.
    for ( i = 0; i <= m; i++) {
    	printf("\n\tMatrisin %d. iterasyonu\n",i);	//*Her Satýr sonunda çözüm matrisi ekrana yazdýrýlýr.
    	printMatrix(L,m+1,n+1);
        for ( j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {						//*	Çözüm matrisin ilk satýr ve ilk sütunundaki hücrelere 0 (Sýfýr) deðeri yazýlýr.			
                L[i][j] = 0;								
            } else if (str1[i - 1] == str2[j - 1]) {	//*	Iki dizideki harfler eþleþirse çözüm matrisi güncellenir.	
                L[i][j] = L[i - 1][j - 1] + 1;			//*	Çözüm matrisinde diagonal olarak sað altta bulunan deðer 1 arttýrýlýr(INC).
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);//*	Harfler eþleþmezse sol veya üstteki elemanlardan büyük olaný hücreye yazýlýr.
            }
        }
    }
    
    //*Çözüm matrisinin son hali ekrana yazdýrýlýr.
	printf("\n\t<<Cozum Matrisi>>\n");
	printMatrix(L,m+1,n+1);
	
	
	//* En uzun ortak sekansýn (lcs) uzunluðu en sað alt köþede oluþturuldu.
	//* Bu oluþan deðer length adýnda bir integer'a atanýyor.
	//*	Ve Ekrana yazdýrýlýyor.
    int length = L[m][n];
	printf("\nEn uzun ifadenin boyutu: %d \n",length);
	
    //* En uzun ortak sekansý bulma
    char *lcs = (char *)malloc((length + 1) * sizeof(char));//*	Ortak sekans için yeni bir dizi oluþturulur. 
    lcs[length] = '\0';										//**Dizi boþaltýlýr.

    i = m, j = n;
    while (i > 0 && j > 0) {					//*	Sað alt köþeden yýkarý veya sola doðru hareket ederek
        if (str1[i - 1] == str2[j - 1]) {		//*	Dizilerin son elemanlarýndan baþlanarak geriye doðru kontrol yapýlýyor,	
            lcs[length - 1] = str1[i - 1];		//*	Harfler eþlesiyorsa ortak sekans dizisinin sonuna bu harf yazýlýyor.						
            i--;		
            j--;		//index deðerleri güncelleniyor.
            length--;	//printf("diagonal\n");
        } else if (L[i - 1][j] > L[i][j - 1]) {	//*	Harfler eþit deðilse çözüm matrisinde gidilecek yön belirlenir. 
            i--;		//printf("yukari\n");						//*	Soldaki sayý büyükse çözüm matrisinde sola;
        } else {								//*	Yukardaki sayý büyükse çözüm matrisinde yukarý ilerletilir.
            j--;		//printf("sola\n");
        }
    }
	
    //* En uzun ortak sekans ekrana yazdýrýlýr.
    printf("En Uzun Ortak Sekans: %s\n", lcs);

    //* Oluþturduðumuz dizileri bellekten serbest býrakýlýr.
    for ( i = 0; i <= m; i++) {
        free(L[i]);
    }
    free(L);
    free(lcs);
}

int main() {
   
   //char str1[]= "c"; 
   //char str2[]= "c";
	
	

	
   	//* Ýki char dizisi tanýmlanýr ve bu dizilere girdiler kullanýcýdan alýnýr.
    char str1[STRINGSIZE]; 
    char str2[STRINGSIZE];
    printf("\nBirinci diziyi girin\n ");	//*Kullanýcýdan birinci dizi istenir.
    gets(str1);								//*Dizi alýnýr. str1
			
	printf("\nIkinci diziyi girin.\n ");	//*Kullanýcýdan ikinci dizi istenir.
    gets(str2);								//*Dizi alýnýr. str2
	
		
	
    //*Alýnýnan dizilerdeki en uzun ortak sekans bulan ve ekrana yazdýran fonksiyon çaðrýlýr.
    findLongestCommonSequence(str1, str2);

    return 0;
}


