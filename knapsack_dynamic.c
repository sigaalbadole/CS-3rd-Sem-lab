#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
int max(int a, int b) { return (a > b)? a : b; }

int knapsack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}

int main()
{   int n, *wt, *val;
    int W;
    clock_t t;
    double time_taken;
    printf("Enter the value of n and W : ");
    scanf("%d %d", &n, &W);
    wt = (int*)malloc(n * sizeof(int));
    val = (int*)malloc(n * sizeof(int));

    for(int i =0; i<n; i++)
    {
        printf("Enter the Value and Weight : ");
        scanf("%d %d", &val[i], &wt[i]);  
    }
    t = clock();
	printf("%d \n", knapsack(W, wt, val, n));
    t = clock() - t;
    time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("Time Taken = %lf \n", time_taken);
	return 0;
}