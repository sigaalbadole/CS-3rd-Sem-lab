#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r - m;
	int L[n1], R[n2];
	for(i=0; i<n1; i++)
	{
		L[i] = arr[l+i];
	}
	for(j=0; j<n2; j++)
		R[j] = arr[m+1+j];
	
	i=0;
	j=0;
	k=l;
	
	while(i<n1 && j<n2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int m = l+(r-1)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}
void printArray(int arr[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr10[10], arr100[100], arr200[200], arr300[300], arr400[400];
	double time_taken;
	for(int q=0; q<10; q++)
		arr10[q] = rand()%100;
	for(int q=0; q<100; q++)
		arr100[q] = rand()%100;
	for(int q=0; q<200; q++)
		arr200[q] = rand()%100;
	for(int q=0; q<300; q++)
		arr300[q] = rand()%100;
	for(int q=0; q<400; q++)
		arr400[q] = rand()%100;
	//printArray(arr10, 10);
	//printArray(arr100, 100);
	//printArray(arr500, 500);
	//printArray(arr1000, 1000);
	//printArray(arr2000, 2000);	
	clock_t t;
	//MergeSort begins
	t = clock();
	mergeSort(arr10, 0, 9);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time = %f", time_taken);
	//printArray(arr10, 10);
	
	t = clock();
	mergeSort(arr100, 0, 99);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time = %f", time_taken);
	//printArray(arr100, 100);
	
	t = clock();
	mergeSort(arr200, 0, 199);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time = %f", time_taken);
	//printArray(arr500, 500);
	
	t = clock();
	mergeSort(arr300, 0, 299);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time = %f", time_taken);
	//printArray(arr1000, 1000);
	
	t = clock();
	mergeSort(arr400, 0, 399);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time = %f", time_taken);
	//printArray(arr2000, 2000);
	return 0;
}