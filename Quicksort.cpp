//Quicksort by David Talabi - February 21, 2019

#include <iostream>
#include<cstdlib>
using namespace std;

int Partition(int A[], int start, int end)
{
	int pivot = A[end];
	int i = start - 1;
	
	for(int j=start; j<=end-1; j++)
	{
	if (A[j] <= pivot)
	{
	i += 1;
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
	}
	}
	int temp = A[i+1];
	A[i+1] = A[end];
	A[end] = temp;
	return i+1;

}

int randompartition(int A[], int start, int end)
{
	int random;
	random = start + rand() % (end-start);
	
	int temp = A[random];
	A[random] = A[end];
	A[end] = temp;
	
	return Partition(A,start,end);
}

void quicksort(int A[], int start, int end)
{
	if (start < end) {
		int partitionindex;
		partitionindex = randompartition(A,start,end);
		
		quicksort(A,start,partitionindex - 1);
		quicksort(A,partitionindex+1, end);
	}
}

void displayarray(int A[], int n) //function to display array elements, will be recursively called in main function
{
	for(int i=0; i<n; i++)
		cout << A[i] << ";"; //displaying the array, the semi colons are so that it shows a semi colon after every number that is printed
}


int main() //Main function where we recursively call the functions made earlier so that we have an output and the user also inputs the array size and elements
{

int n; //Array size	
cin >> n; //User inputs array size
int A[n]; //Initializing array with n elements that user inputs

for(int i=0; i<n; i++)
	cin >> A[i]; //user inputs array elements

	heapSort(A,n); //recursively calling heapsort function made earlier to sort the array
	displayarray(A,n); //recursively calling display array function to display the final sorted array
	
return 0;
}
