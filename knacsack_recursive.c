#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int *wt, int *val, int n)
{
	if (n == 0 || W == 0)
		return 0;

	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	else
		return max(
			val[n - 1]
				+ knapSack(W - wt[n - 1],
						wt, val, n - 1),
			knapSack(W, wt, val, n - 1));
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
	printf("%d \n", knapSack(W, wt, val, n));
    t = clock() - t;
    time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("Time Taken = %lf \n", time_taken);
	return 0;
}
