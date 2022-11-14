#include <stdio.h>
#include <stdlib.h>
#define INF 999

int count(int coins[], int n, int sum)
{
	int table[sum+1];
	table[0] = 0;
	for (int i = 1; i <= sum; i++)
        table[i] = INF;
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j < n; j++)
         if(coins[j] <= i) 
            {
                int sub_res = table[i - coins[j]];
                if (sub_res != INF && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
   
 	}
    	if (table[sum] == INF)
       		return -1;
 
    return table[sum];
}


int main()
{
	
	int n, sum; 
	printf("Enter the sum and number of coins :");
	scanf("%d %d", &sum, &n);
	int *coins;
	coins = (int *)malloc(n*sizeof(int));
	printf("Enter the denomination of coins :\n");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &coins[i]);
	}
	printf("Least number of coins required for %d is %d\n", sum, count(coins, n, sum));
	return 0;
}