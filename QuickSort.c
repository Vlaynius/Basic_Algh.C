#include<stdio.h>
#include<stdlib.h>

void swap(int Array[],int i ,int j);
int partition(int Arr[], int low, int high);
void quickSort(int Arr[], int low, int high);
void printArray(int Arr[]);
int length(int Arr[]);

int main(){
	int Arr[] = { 5,8,3,5,7,9,2,3,5,4,6,'\0'};
	int N = length(Arr);
	
	quickSort(Arr, 0 , N-1);
	printf("Sorted Array\n");
	printArray(Arr);
	
return 0;
}

void swap(int Array[],int i ,int j){	//function to swap two elements
	int temp = Array[i];
	Array[i] = Array[j];
	Array[j] = temp;
}



int partition(int Arr[], int low, int high){
	
/* This function takes last element as pivot,
** places the pivot element at its correct position
** in sorted array, and places all smaller to left
** of pivot and all greater elements to right of pivot*/
	
	int pivot = Arr[high];	//Choosing the Pivot
	
	// Index of smaller element and indicates
    // the right position of pivot found so far
	int i = (low -1);
	
	int j;
	for(j = low; j <= high; j++){
		
		if(Arr[j] < pivot){	// If current element is smaller than the pivot
			
			// Increment index of smaller element
			i++;
            swap(Arr, i, j);
		}
	}
	swap(Arr, i + 1, high);
    return (i + 1);
	
	
}

/*The main function that implements QuickSort
**arr[] --> Array to be sorted,
**low --> Starting index,
**high --> Ending index*/

void quickSort(int Arr[], int low, int high){
	
	if (low < high) {
 
    	// pi is partitioning index, arr[p]
        // is now at right place
        int adr = partition(Arr, low, high);
 
        // Separately sort elements before
    	// partition and after partition
        quickSort(Arr, low, adr - 1);
        quickSort(Arr, adr + 1, high);
        }
    }



void printArray(int Arr[]){
	//function to print array
	
	int N = length(Arr);
	int i;
	for(i = 0; i < N; i++){
		printf(" %d ",Arr[i]);
	}
	
}

int length(int arr[]){
	int i, count = 0;
	for(i=0; arr[i]!='\0'; i++)
    {
        count++;
    }
	
	return count;
}
