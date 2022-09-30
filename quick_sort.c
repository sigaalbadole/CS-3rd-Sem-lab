#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data10[10], data100[100], data200[200], data300[300], data400[400];
  for(int q=0, q<10, q++)
  data100[q]=rand()%100;
  for(int q=0, q<100, q++)
  data200[q]=rand()%100;
  for(int q=0, q<200, q++)
  data300[q]=rand()%100;
  for(int q=0, q<300, q++)
  data400[q]=rand()%100;
  
  clock_t t;
  double time_taken;
  t=clock();
  quickSort(data10, 0, 9);
  t=clock()-t
  time_taken=((double)t)/CLOCKS_PER_SEC;
  printf("Time Taken = %f", time_taken);
  
  t=clock();
  quickSort(data100, 0, 99);
  t=clock()-t
  time_taken=((double)t)/CLOCKS_PER_SEC;
  printf("Time Taken = %f", time_taken);
  
  t=clock();
  quickSort(data200, 0, 199);
  t=clock()-t
  time_taken=((double)t)/CLOCKS_PER_SEC;
  printf("Time Taken = %f", time_taken);
  
  t=clock();
  quickSort(data300, 0, 299);
  t=clock()-t
  time_taken=((double)t)/CLOCKS_PER_SEC;
  printf("Time Taken = %f", time_taken);
  
  t=clock();
  quickSort(data400, 0, 399);
  t=clock()-t
  time_taken=((double)t)/CLOCKS_PER_SEC;
  printf("Time Taken = %f", time_taken);
}