#include <stdio.h>
#include <stdlib.h>

	
typedef struct node{
	int data;
	struct node *next;
}Node;

typedef struct queue{
	int count;
	struct Node* front;
	struct Node* rear;
}Queue;

void initialize(struct Queue *q);
int isEmptyQueue(struct Queue *q);
void Enqueue(int data, struct Queue *q);
int Dequeue(struct Queue* q);

void main(void){
	Queue *q;
	q = (struct Queue*)Malloc(sizeof(struct Queue));
	initialize(*q);
	Enqueue(10, *q);
	Enqueue(11,*q);
	Enqueue(12,*q);
	
	printf("%d\n",Dequeue(*q));
	printf("%d\n",Dequeue(*q));
	printf("%d\n",Dequeue(*q));
	


}

void initialize(Queue *q){
	Node * rear = (struct Node*) malloc(sizeof(struct Node));
	Node *front = (struct Node*) malloc(sizeof(struct Node));
	q -> count = 0;
	q -> rear = NULL;
	q -> front = NULL;
}

int isEmptyQueue(struct Queue *q){
	return (q -> rear == NULL);
}

void Enqueue(int data, struct Queue *q){
	struct Node* new_node;
	new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node -> next = NULL;
	new_node -> data = data;
	if(q -> front == NULL){
		q -> front = new_node;
		q -> rear = new_node;		
	}else{
		q -> rear -> next = new_node;
		q -> rear = new_node;
	}
	q -> count++; 
	
}

int Dequeue(struct Queue* q){
	int n;
	struct Node* temp;
	temp = q -> front;
	n = temp -> data;
	q -> front = q -> front -> next;
	free temp;
	q -> count --;
	return n;
}
