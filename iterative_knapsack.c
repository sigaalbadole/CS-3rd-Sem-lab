#include<stdio.h>
#include<time.h>

#define N 128

int CostTable[N][N];
int Weight[N];
int Benefit[N];



int max(int a, int b){
    return a > b ? a : b;
}

void knapsack(int n, int W) {
  int w, i;
  for(w=0; w<=W; w++) {
    CostTable[0][w] = 0;
  }

  for(i=0; i<=n; i++) {
    CostTable[i][0] = 0;
  }

  for(i=1; i<=n; i++) {
    for(w=1; w<=W; w++) {
      if(Weight[i] > w) {
        CostTable[i][w] = CostTable[i-1][w];
      }
      else {
        if (Benefit[i]+CostTable[i-1][w-Weight[i]] > CostTable[i-1][w]) {
          CostTable[i][w] = Benefit[i] + CostTable[i-1][w-Weight[i]];
        }
        else {
          CostTable[i][w] = CostTable[i-1][w];
        }
      }
    }
  }
}

void printCostTable(int item_count,int total_weight){
    for(int i = 0; i <= item_count; ++i){
        printf("%d:  ", i);
        for(int w = 0; w <= total_weight; ++w)
            printf("%d ", CostTable[i][w]);
        printf("\n");
    }
}

int main(){
	int n;
	printf("Enter the number of elements you want to enter: \n");
	scanf("%d",&n);
	int total_weight;
	printf("Enter the total weight :\n");
	scanf("%d",&total_weight);
	printf("Enter the weight and profit :\n");
    for(int i =0; i<n;i++){
    	
    	scanf("%d %d",&Weight[i],&Benefit[i]);
    }
    clock_t start, end;
    double cpu_time_used;
     
    start = clock();
    knapsack(n,total_weight);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
       

    printf("Max Benefit: %d\n\n", CostTable[n][total_weight]);
    printf("Time taken: %lf\n",cpu_time_used);

    printCostTable(n,total_weight);

    return 0;
}