#include <stdio.h>
#include <stdlib.h>
int V = 0;
int isSafe(int v, int graph[V][V], int path[], int pt)
{
  if (graph[path[pt - 1]][v] == 0)
    return 0;
  for (int i = 0; i < pt; i++)
    if (path[i] == v)
      return 0;
  return 1;
}

int hamCycle(int graph[V][V], int path[], int pt)
{
  if (pt == V)
  {
    if (graph[path[pt - 1]][path[0]] == 1)
      return 1;
    else
      return 0;
  }
  for (int v = 1; v < V; v++)
  {
    if (isSafe(v, graph, path, pt))
    {
      path[pt] = v;
      if (hamCycle(graph, path, pt + 1) == 1)
        return 1;
      path[pt] = -1;
    }
  }
  return 0;
}
void printSolution(int path[])
{
  for (int i = 0; i < V; i++)
    printf("%d->", path[i]);
  printf(" %d ", path[0]);
  printf("\n");
}
int printIfHamExists(int graph[V][V])
{
  int *path = (int *)malloc(sizeof(int) * V);
  for (int i = 0; i < V; i++)
    path[i] = -1;
  path[0] = 0;
  if (hamCycle(graph, path, 1) == 0)
  {
    printf("\nSolution does not exist");
    return 0;
  }
  printSolution(path);
  return 1;
}
int main()
{

  printf("Enter the value for V: ");
  scanf("%d", &V);

  int graph[V][V] ;

  for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
      scanf("%d", &V[i][j]);

  printIfHamExists(graph1);
  return 0;
}