#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define INF 999999
int main()
{
	int V;
	printf("Enter the number of Vertices : ");
	scanf("%d",&V);
	int G[V][V];
	int i,j;
	printf("Enter the Adjacency List :\n");
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d",&G[i][j]);
		}
	}
	int no_edge;
	int selected[V];
	memset(selected,false,sizeof(selected));
	no_edge=0;
	selected[0]=true;
	
	int row, col;
	printf("Edge  : Weight\n");
	
	while(no_edge<V-1)
	{
		int min= INF;
		row=col=0;
		for(i=0;i<V;i++)
		{
			if(selected[i])
			{
				for(j=0;j<V;j++)
				{
					if(!selected[j]&&G[i][j])
					{
						if(min>G[i][j])
						{
							min=G[i][j];
							row=i;
							col=j;
						}
					}
				}
			}
		}
	
		printf("%d - %d : %d\n", row,col,G[row][col]);
		selected[col] = true;
		no_edge++;
		}
	return 0;
}