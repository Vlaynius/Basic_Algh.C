#include <stdio.h>
#include <stdlib.h>
typedef struct link{
	int data;
	struct link *next;
}node;

int main(){

int i, n = 41, m=5;
	
	node* t = (node*)malloc(sizeof (node));	
	node* x = t;
	t -> data =1;
	t -> next =t;
	for(i=2; i<=n; n++){
		x = (x-> next = malloc (sizeof*x));
		x -> data = i;
		x -> next = t;
	}
	while(x != x->next){
		 for(i=1 ;i <= m;i++){
		 x = x ->next;}
		 x -> next = x ->next ->next;
		 n--;
	}
	printf("%d\n", x -> data);
	
	
return 0;
}

