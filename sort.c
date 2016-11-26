//Iarla Scaife 2016

#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef int bool;
unsigned int probes = 0;


int partition(int *data, int first, int last) {

	int x = data[last];
	int i = first - 1;

	for (int j = first; j < last; j++) { //loop over data

		if (data[j] <= x) { //compare current value with the pivot

			i++;
			int temp = data[i]; //Move smaller values leftwards
			data[i] = data[j];
			data[j] = temp;
		}
		probes++;
	}

	int temp = data[i + 1]; //Swap the rightmost value with 
	                        //the smallest value that is larger than the pivot.
	data[i + 1] = data[last];
	data[last] = temp;
	return i + 1;           // return a new pivot
}
	
void quick_sort(int *data, int first, int last) {

	if (first < last) {

		int q = partition(data, first, last); //divide and begin to sort data using partition.
		quick_sort(data, first, q - 1);     //recursively call quicksort on data left of 
		                                    //new pivot returned by partition.
		quick_sort(data, q + 1, last);      //recursively call quicksort on data right of 
		                                    //new pivot returned by partition.
	}
}


int main() {

	int testData[] = { 1, 54, 76, 42, 12, 9, 4, 6, 45, 109 }; //define array of unsorted test data

	int size = sizeof(testData) / sizeof(int);

	for (int i = 0; i < size; i++) {  //print the unsorted array
		printf("%i ", testData[i]); 
	}
	printf("\n");


	quick_sort(testData, 0, size-1);

	for (int i = 0; i < size; i++) { //print the sorted array
		printf("%i ", testData[i]);
	}

	printf("\nNumber of probes is %i\n", probes); //Print number of probes
	getchar();  //hang the program to avoid command prompt exiting suddenly

	return 0;
}