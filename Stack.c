#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* ptr;
}top,top1,tmp;

int Peek();
void push(int data, int count);
int pop(int count);
int isEmpty();
void stackCount(int count);
void create();

int main(){
	int data;
	int count = 0;
	push(12,count);
	push(15,count);
	data= pop(count);
	printf("data1 == %d",data);
	printf("data2 == %d",pop(count));
	return 0;
}

int Peek(){
	int ret = top -> data;
	return ret;
}
void push(int data, int count){
	if(top == NULL){
		top = (struct node*) malloc (sizeof(node));
		top -> ptr = NULL;
		top -> data = data;
		
	}
	else{
		tmp = (struct node*) malloc (sizeof(node));
		tmp -> ptr = top;
		tmp  -> data = data;
		top = tmp;
	}
	count ++;
}
int pop(int count){
	int ret;
	top1 = top;
		if(top == NULL)
			printf("ERROR : stack is Empty");
		return -1;
		else{	
			ret = top -> data;
			top1 = top -> ptr;
			free top;
			top = top1;
			count --;
			return ret;
		}
}
int isEmpty(){
	if(top == NULL)
		printf("\n stack is Empty");
	else 
		printf("\n stack is not Empty with number of elements %d ",count);
}

void stackCount(int count){
	printf("\n 	NO. of elements in stack :  %d", count);
}
void create(){
	top = NULL;
}

//Dizi ile Stack

/*	static dizi stack
	int maxsize=8;
	int stack[8]
	int top = -1;	

void push(int data){
	if(!isfull){
		top ++;
		stack[top] = data;		
	}else printf("Full\n");
}

int pop(){
	int data;
	if(!isempty){
		top --;
		data = stack[top];
		return data; 
	}else printf("EMPTY");
}

int isempty(){
	if(top == -1){
		return 1;
	}else return 0;
}

int isfull(){
	if(top == maxsize)
		return 1;
	else return 0;
	
}
int peek(){
	return stack[top];
}
*/
