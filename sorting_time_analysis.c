#include <stdio.h>
#include <time.h>


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int arr[], int n){
	for (int i = 0;i<n;i++){
		for (int j = 0; j < n-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j]=temp;	
			}
		}	
	}
}

void selection_sort(int arr[], int n)
{
    int i, j, m;
 
    for (i = 0; i < n-1; i++)
    {
       
        m = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[m])
            m = j;
 
        if(m!=i)
            swap(&arr[m], &arr[i]);
    }
}

void insertion_sort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

int main(){
	
	FILE *ptr, *p;
	int ch=0;

	int n;
	int arr[100000];
	int demo[] = {56, 89, 12, 0, -1, 23};
	double time_taken ;

	n=0;
	ptr = fopen("input.txt", "r");
	
	if (NULL == ptr) {
        	printf("file can't be opened \n");
    	}

	fscanf(ptr, "%d", &ch);    
	  while (!feof (ptr))
	    {  
	      arr[n] = ch;
		n++;
	      fscanf (ptr, "%d", &ch);      
	    }
	  fclose (ptr);   
	
	clock_t t;

	// BUBBLE SORT

	t = clock();
		bubble_sort(arr,n);
		//selection_sort(arr,n);
		//insertion_sort(arr,n);
	t = clock() - t;

	time_taken = ((double)t)/CLOCKS_PER_SEC;

	p = fopen("output.txt", "w");
	if (NULL == p) {
        	printf("file can't be opened \n");
    	}

	for(int i = 0;i<n;i++){
		fflush(stdin);
		fprintf(p, "%d\n", arr[i]);
	}

	printf("- bubble sort time required: %f\n", time_taken);

	// SELECTION SORT
n=0;
	ptr = fopen("input.txt", "r");
	
	if (NULL == ptr) {
        	printf("file can't be opened \n");
    	}

	fscanf(ptr, "%d", &ch);    
	  while (!feof (ptr))
	    {  
	      arr[n] = ch;
		n++;
	      fscanf (ptr, "%d", &ch);      
	    }
	  fclose (ptr);   
	

	t = clock();
		//bubble_sort(arr,n);
		selection_sort(arr,n);
		//insertion_sort(arr,n);
	t = clock() - t;

	time_taken = ((double)t)/CLOCKS_PER_SEC;

	p = fopen("output.txt", "w");
	if (NULL == p) {
        	printf("file can't be opened \n");
    	}

	for(int i = 0;i<n;i++){
		fflush(stdin);
		fprintf(p, "%d\n", arr[i]);
	}

	printf("- selection sort time required: %f\n", time_taken);

	// INSERTION SORT
n=0;
	ptr = fopen("input.txt", "r");
	
	if (NULL == ptr) {
        	printf("file can't be opened \n");
    	}

	fscanf(ptr, "%d", &ch);    
	  while (!feof (ptr))
	    {  
	      arr[n] = ch;
		n++;
	      fscanf (ptr, "%d", &ch);      
	    }
	  fclose (ptr);   
	

	t = clock();
		//bubble_sort(arr,n);
		//selection_sort(arr,n);
		insertion_sort(arr,n);
	t = clock() - t;

	time_taken = ((double)t)/CLOCKS_PER_SEC;

	p = fopen("output.txt", "w");
	if (NULL == p) {
        	printf("file can't be opened \n");
    	}

	for(int i = 0;i<n;i++){
		fflush(stdin);
		fprintf(p, "%d\n", arr[i]);
	}

	printf("- insertion sort time required: %f\n", time_taken);

	return 0;
}