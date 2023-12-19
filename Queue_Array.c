#include <stdio.h>

#define MAXSIZE 20


void main(){
	int queue[MAXSIZE];
	int value ;
	int front , rear , size = 0;
	
	
	
}

void Enqueue(int value, int queue[], int rear , int size){
	if(size < MAXSIZE){
		if(size < 0){
			queue[0] = value;
			front = rear = 0 ;
			size = 1;
		}
		else if(rear == MAXSIZE -1){
			queue[0] = value;
			rear = 0;
			size ++;
		}
		else{
			queue[rear +1] = value;
			rear ++;
			size ++;
		}
	}else{
		printf("\n queue is FULL \n");
	}
}

int Dequeue(int queue[],int front, int size){
	int temp;
	if(size > 0){
		if(front == MAXSIZE -1){
			temp = queue [front];
			front = 0;
			size --;
			
		}else{
		temp = queue[front];
		front ++;
		size --;
			
		}
		
	}else{
		printf("\n queue is Empty \n");
		return NULL;
	}
		
	return temp;
}