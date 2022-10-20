#include <stdio.h>
#include <time.h>
int binomial_coefficient(int n, int k)
{
	if(k>n)
	{
		return 0;
	}
	if(k==0 || k == n)
		return 1;
	else
	{
		return binomial_coefficient(n-1, k-1) + binomial_coefficient(n-1, k);
	}
}
int main()
{
	int n, k;
	clock_t t;
	double time_taken;
	printf("Enter the values of n and k for C(n,k) : ");
	scanf("%d %d", &n, &k);
	t = clock();
	printf("Value of C(%d, %d) = %d \n", n, k, binomial_coefficient(n, k));
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time taken = %lf\n", time_taken);
    return 0;
}