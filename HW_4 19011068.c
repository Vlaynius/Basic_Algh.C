//Harfin sekans i�in se�ilip se�ilmedi�i bilgisini de saklayan ek bir matris olu�turulmal�d�r.
//birden fazla lcs varsa hepsi ekrana yazd�r�lmal�

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGSIZE 50	//Max string size 50 atand�.


//Girilen iki integer de�erden b�y�k olan�n� d�nd�ren fonksiyon.
int max(int a, int b) {
    if(a>b){
   	   	  return a;	//* int a, int b'den b�y�kse a d�nd�r�l�r.
	}else return b;	//* int b b�y�kse veya iki say� e�itse b d�nd�r�l�r. 
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

// En uzun ortak sekans� bulan ve boyutunu d�nd�ren fonksiyon.
void findLongestCommonSequence(char *str1, char *str2) {
    //Olu�turuca��m�z ��z�m matrisinin boyutlar� i�in kullanaca��m�z iki dizinin uzunlular� al�n�r.
	int m = strlen(str1);	//str1 dizisinin uzunlu�u integer m'ye atan�r.
    int n = strlen(str2);	//str2 dizisinin uzunlu�u integer n'ye atan�r.
	
	int i,j;
	
    // ��z�m matrisi olu�turulur. Haf�zada yer ayarlan�r.
    int **L = (int **)malloc((m + 1) * sizeof(int *));
    for ( i = 0; i <= m; i++) {
        L[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    for ( i = 0; i <= m; i++) {
   		for ( j = 0; j <= n; j++){
   			L[i][j] = 0;
		   }
	}
	//*��z�m matrisinin ilk hali ekrana yazd�r�l�r.	
	printf("\n  <<Cozum Matrisinin ilk hali>>\n");
	
    // �� i�e iki for d�ng�s� ile ��z�m matrisi doldurulur.
    for ( i = 0; i <= m; i++) {
    	printf("\n\tMatrisin %d. iterasyonu\n",i);	//*Her Sat�r sonunda ��z�m matrisi ekrana yazd�r�l�r.
    	printMatrix(L,m+1,n+1);
        for ( j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {						//*	��z�m matrisin ilk sat�r ve ilk s�tunundaki h�crelere 0 (S�f�r) de�eri yaz�l�r.			
                L[i][j] = 0;								
            } else if (str1[i - 1] == str2[j - 1]) {	//*	Iki dizideki harfler e�le�irse ��z�m matrisi g�ncellenir.	
                L[i][j] = L[i - 1][j - 1] + 1;			//*	��z�m matrisinde diagonal olarak sa� altta bulunan de�er 1 artt�r�l�r(INC).
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);//*	Harfler e�le�mezse sol veya �stteki elemanlardan b�y�k olan� h�creye yaz�l�r.
            }
        }
    }
    
    //*��z�m matrisinin son hali ekrana yazd�r�l�r.
	printf("\n\t<<Cozum Matrisi>>\n");
	printMatrix(L,m+1,n+1);
	
	
	//* En uzun ortak sekans�n (lcs) uzunlu�u en sa� alt k��ede olu�turuldu.
	//* Bu olu�an de�er length ad�nda bir integer'a atan�yor.
	//*	Ve Ekrana yazd�r�l�yor.
    int length = L[m][n];
	printf("\nEn uzun ifadenin boyutu: %d \n",length);
	
    //* En uzun ortak sekans� bulma
    char *lcs = (char *)malloc((length + 1) * sizeof(char));//*	Ortak sekans i�in yeni bir dizi olu�turulur. 
    lcs[length] = '\0';										//**Dizi bo�alt�l�r.

    i = m, j = n;
    while (i > 0 && j > 0) {					//*	Sa� alt k��eden y�kar� veya sola do�ru hareket ederek
        if (str1[i - 1] == str2[j - 1]) {		//*	Dizilerin son elemanlar�ndan ba�lanarak geriye do�ru kontrol yap�l�yor,	
            lcs[length - 1] = str1[i - 1];		//*	Harfler e�lesiyorsa ortak sekans dizisinin sonuna bu harf yaz�l�yor.						
            i--;		
            j--;		//index de�erleri g�ncelleniyor.
            length--;	//printf("diagonal\n");
        } else if (L[i - 1][j] > L[i][j - 1]) {	//*	Harfler e�it de�ilse ��z�m matrisinde gidilecek y�n belirlenir. 
            i--;		//printf("yukari\n");						//*	Soldaki say� b�y�kse ��z�m matrisinde sola;
        } else {								//*	Yukardaki say� b�y�kse ��z�m matrisinde yukar� ilerletilir.
            j--;		//printf("sola\n");
        }
    }
	
    //* En uzun ortak sekans ekrana yazd�r�l�r.
    printf("En Uzun Ortak Sekans: %s\n", lcs);

    //* Olu�turdu�umuz dizileri bellekten serbest b�rak�l�r.
    for ( i = 0; i <= m; i++) {
        free(L[i]);
    }
    free(L);
    free(lcs);
}

int main() {
   
   //char str1[]= "c"; 
   //char str2[]= "c";
	
	

	
   	//* �ki char dizisi tan�mlan�r ve bu dizilere girdiler kullan�c�dan al�n�r.
    char str1[STRINGSIZE]; 
    char str2[STRINGSIZE];
    printf("\nBirinci diziyi girin\n ");	//*Kullan�c�dan birinci dizi istenir.
    gets(str1);								//*Dizi al�n�r. str1
			
	printf("\nIkinci diziyi girin.\n ");	//*Kullan�c�dan ikinci dizi istenir.
    gets(str2);								//*Dizi al�n�r. str2
	
		
	
    //*Al�n�nan dizilerdeki en uzun ortak sekans bulan ve ekrana yazd�ran fonksiyon �a�r�l�r.
    findLongestCommonSequence(str1, str2);

    return 0;
}


