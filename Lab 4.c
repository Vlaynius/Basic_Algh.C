#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max	50

void printZCiz(int N,int head,int matris[Max][3]);



int main(){
	int N,i,j,head;
	char tmp;
	int matris[Max][3]={0};
	
	printf("is sayisini girin : ");
	scanf("%d",&N);
	for(i=0;i<N;i++){
		
		printf("is kodunu girin : ");
		scanf("%c",matris[i][0]);	
		
		
		do{
			
			printf("\nis suresini girin : ");
			printf("\nsure 1 den az olamaz \n");
			scanf("%d",matris[i][1]);
			
		}while(matris[i][1] < 1);
	
		printf("\nlink listesini girin : ");
		scanf("%d",matris[i][2]);
	}
	
	do{
		printf("\nhead i girin = ");
		scanf("%d",&head);
	}while(head >=0 && head <N-1);
	
	printZCiz(N,head,matris);
	
	return 0;
}	



void printZCiz(int N,int head,int matris[Max][3]){
	int i;
	while(list!= -1){
		for(i=0;i<matris[Max][3]){
			
		}
	}
	

	
	
}
