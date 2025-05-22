#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 99999

int mindistance(int dist[],int visited[],int n){
    int min=INT_MAX,index;
    for(int i=0;i<n;i++){
        if(visited[i]!=1 && dist[i]<min){
            min=dist[i];
            visited[i]=1;
            index=i;
        }
    }
    return index;
}

void dijkstra(int **a,int n,int start){
    int dist[n],visited[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=0;
    }
    dist[start]=0;
    for(int i=0;i <n;i++){
        int u=mindistance(dist,visited,n);
        visited[u]=1;
        for(int v=0;v<n;v++)
        {
            if(a[u][v]!=0 && visited[v]!=0 && dist[u]!=INT_MAX && dist[u]+a[u][v]<dist[v]){
                dist[v]=dist[u]+a[u][v];
            }
        }
    }
    printf("Shortest distance from source %d:\n",start);
    for(int i=0;i<n;i++){
        printf("To %d: %d\n",i,dist[i]);
    }
}

int main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    int **a=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
        a[i]=(int *)malloc(n*sizeof(int));
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int start;
    printf("Enter the starting vertex: ");
    scanf("%d",&start);
    dijkstra(a,n,start);
}