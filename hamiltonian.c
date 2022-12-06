#include <stdio.h>
#include <stdbool.h>

void printGraph(int n, int Graph[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",Graph[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int v, int n, int Graph[n][n], int path[], int pos){
    if(Graph[path[pos-1]][v]==0){
        return false;
    }

    for(int i=0; i<pos; i++){
        if(path[i]==v){
            return false;
        }
    }

    return true;

}

bool hamiltonianUtil(int n, int Graph[n][n], int path[], int pos){

    if(pos==n){
        if( Graph[ path[pos-1] ][ path[0] ] == 1 ){
            return true;
        }
        else return false;
    }

    for(int v=1; v<n; v++){
        if(isSafe(v,n,Graph,path,pos)){
            path[pos]=v;

            if(hamiltonianUtil(n,Graph,path,pos+1)==true){
                return true;
            }

            path[pos]=-1;
        }
        
    }

    return false;

}

bool hamiltonian(int n, int Graph[n][n]){
    int path[n];

    for(int v=0; v<n; v++){
        path[v]=-1;
    }

    path[0]=0;

    if(hamiltonianUtil(n,Graph,path,1)==true){
        for(int z=0; z<n; z++){
            printf("%d ",path[z]);
        }
        return true;
    }
    else{
        printf("Hamiltonian Cycle of the given Graph does not Exist");
        return false;
    }
}

int main(){
    int n;
    printf("Enter the number of vertices of the Graph: ");
    scanf("%d",&n);
    int Graph[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("Enter 1 if there is a edge between %d and %d, else enter 0 ",i,j);
            scanf("%d",&Graph[i][j]);
        }
    }

    hamiltonian(n, Graph);
}