#include <stdio.h>
#define MAX 100

int adj[MAX][MAX], indegree[MAX], n;

void toposort(){
    int count  = 0;

    while(count < n){
        int found =0;

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                printf("%d ",i);
                indegree[i]= -1;
                count ++;
                found =1;

                for(int j =0; j< n; j++){
                    if(adj[i][j] ==1) indegree[j] --;
                }
            }
        }
        if(!found)printf("Cycle found. topo sort not possible"); return;
    }
}

int main(){
    printf("Enter number of vertices : ");
    scanf("%d",&n);

    printf("Enter adjacency matrix : " );
    for(int i =0; i <n; i++){
        indegree[i] =0;
        for(int j =0; j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }

    for(int j=0; j<n;j++){
        for(int i=0; i<n; i++){
            if(adj[i][j] ==1) indegree[j]++;
        }
    }
    printf("Topological sort order : ");
    toposort();
}