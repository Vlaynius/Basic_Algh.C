#include<stdio.h> 

// Method to print the array 
void printArray(int arr[],int length) 
{ 
	int i;
	for( i = 0; i < length; i++) 
	{ 
		printf(" %d ", arr[i]); 
	} 
	printf("\n"); 
} 

// Similar to standard partition method. 
// Here we pass the pivot element too 
// instead of choosing it inside the method. 
int partition(int arr[], int low, int high, int pivot) 
{ 
	int i = low; 
	int temp_1, temp_2; 
	int j;
	for( j = low; j < high; j++) 
	{ 
		if (arr[j] < pivot) 
		{ 
			temp_1 = arr[i]; 
			arr[i] = arr[j]; 
			arr[j] = temp_1; 
			i++; 
		} 
		else if(arr[j] == pivot) 
		{ 
			temp_1 = arr[j]; 
			arr[j] = arr[high]; 
			arr[high] = temp_1; 
			j--; 
		} 
	} 
	temp_2 = arr[i]; 
	arr[i] = arr[high]; 
	arr[high] = temp_2; 

	// Return the partition index of an array based on the pivot element of other array.
	return i; 
} 

// Function which works just like quick sort 
void matchPairs(int locks[], int keys[], int low, int high) 
{ 
	if (low < high) 
	{ 
		
		// Choose last int of keys array for locks partition. 
		int pivot = partition(locks, low, high, keys[high]); 

		// Now using the partition of locks choose that for keys partition. 
		partition(keys, low, high, locks[pivot]); 

		// Recur for [low...pivot-1] and [pivot+1...high] for locks and keys array. 
		matchPairs(locks, keys, low, pivot - 1); 
		matchPairs(locks, keys, pivot + 1, high); 
	} 
} 

//Main function
int main() 
{ 
	// locks and keys are represented 
	
//	int locks[] = {1,2,3,4,5,6,7,8,9};		int keys[] = {1,2,3,4,5,6,7,8,9}; //Worst case sýralý dizi
	
//	int locks[] = {9};		int keys[] = {9};
	
//	int locks[] = {1,2,3,4,5,6,7,8,9};		int keys[] = {9,8,7,6,5,4,3,2,1};
	
	int locks[] = {1,8,6,5,9,7,4,3,2};		int keys[] = {6,5,3,8,9,1,7,4,2};
	

	int N = sizeof(locks) / sizeof(locks[0]); //calculates the sizeof arrays and writes on variable N
	printf(" Number of locks and keys : %d \n", N);
	
	//Prints Startting position of arrays
	printf("\tStarting Stuation \n\n");
	printf("\tlocks \n");
	printArray(locks,N);
	printf("\tkeys \n");
	printArray(keys,N);
	printf("\n\n");
	
	// Method based on quick sort which 
	// matches locks and keys 
	matchPairs(locks, keys, 0, N-1); 
	
	
	//prints matched arrays
	printf("Matched locks and keys are : \n"); 
	
	printArray(locks,N); 
	printArray(keys,N); 
	
	return 0;
} 

