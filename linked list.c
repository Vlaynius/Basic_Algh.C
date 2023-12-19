#include <stdio.h>
#include <stdlib.h>

//int struct node*link;

typedef struct link{
	int data;
	struct link *next;
}node;


typedef struct Doublelink{
	int data;
	struct Doublelink *next;
	struct Doublelink *prev;
}Dnode;

/* 	linkli list 
	üzerinde gezinmek için
	for(t = head; t != NULL; t= t->next)	
*/





int main(){
	link head = (node *)malloc (sizeof node); //head adýnda bir node ürettik
	
	return 0;
}

//baþa eleman eklemek

node* insert_top(int num, node*head){
	node *new_node;	
	new_node = (node*)malloc(sizeof (node));
	new_node -> data = num; 
	new_node -> next = head;
	head = new_node;
	return head;
}

//araya eleman eklemek

node* insert_before(int num, int next_num, node* head){	
	node* current_node = head;
	node* new_node;
	while(current_node -> next ->data != next_num){
		current_node = current_node-> next;
	}
	new_node = (node*) malloc(sizeof(node));
	new_node -> data = num;
	new_node ->next = current_node ->next;
	current_node -> next = new_node;
	
	return head;
}

 //eleman silmek
 
 node* delete_value(int num,node* head){
	node* current_node = head;
	node* prev;
	while(current_node !=NULL){
		if(current_node -> data == num){
			if(current_node == head){
				head = current_node -> next;
			}else{
				prev->next = current_node -> next;	
			}	
		free current_node;			
		}
		
		prev = current_node;
		current_node = current_node->next;
	}
	

	/*
	if(Del_num == head -> data){
		head = head -> next;
		free current_node;
	}
	
	while(current_node -> next -> data != Del_num){
		current_node = current_node->next;
	}
	node* tmp = current_node ->next;					//silinecek node'u tmp aktarýp free ettik 
	current_node ->next = current_node ->next ->next;	//hafýza da artýk yer kaplamýyor. 
	free tmp;*/
	
 return head;
 }
	
	//Double linkli liste eleman eklemek
	
	Dnode* insert_before_double(int num,int next_num, Dnode* head){
		Dnode* current_node = head;
		Dnode* new_node;

		while(current_node -> next -> data != next_num ){
			current_node = current_node -> next;
		}
		new_node = (Dnode*) malloc(sizeof(Dnode));
		new_node -> data = num;
		new_node -> next = current_node ->next;
		current_node -> next -> prev = new_node;
		current_node ->next = new_node;
		new_node -> prev = current_node;
		
		return head;
	}
	
	//Double linkli list eleman silme
	
	Dnode* delete_value_double(int num, Dnode* head){
		Dnode * current_node = head;
		Dnode* del;
		
		while(current_node =! NULL){
			if(current_node -> next -> data == num){
				if(current_node == head){
					head = current_node -> next;
					del = current_node;
				}else{
					del = current_node ->next;
					del -> next -> prev = del -> prev;
					del -> prev -> next = del -> next; 
				}
			}
				free del;
		}		
		return head;
	}