#include <stdio.h>
#include <time.h>

int min(int a, int b);

int binom_coeff(int n, int k)
{
	int c[n+1][k+1];
	int i, j;
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<min(i,k); j++)
		{
			if(j==0 || j==i)
			{
				c[i][j] = 1;
			}
			else
			{
				c[i][j] = c[i-1][j-1] + c[i-1][j];
			}
		}
	}
	return c[n][k];
}
int min(int a, int b)
{
	if(a>=b)
	return b;
	else
	return a;
}
int main()
{
	int n, k;
	clock_t t;
	double time_taken;
	printf("Enter the values of n and k for C(n,k) : ");
	scanf("%d %d", &n, &k);
	t = clock();
	printf("Value of C(%d, %d) = %d \n", n, k, binom_coeff(n, k));
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time taken = %lf\n", time_taken);
    return 0;
