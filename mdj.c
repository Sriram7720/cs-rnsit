#include<stdio.h>
#define max 10
#define startnode 0
#define inf 99

void dij(int cost[max][max],int n);

int main(){
    int i,n,cost[max][max],j;
    printf("\n enter the number of vertices \n");
    scanf("%d",&n);
    printf("\n enter the cost matrix \n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    dij(cost,n);
return 0;
}

void dij(int cost[max][max],int n){
    int distance[max],pred[max],visited[max],nextnode,i,j,mindistance,count;
    for(i=0;i<n;i++){
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while(count<n-1){
        mindistance = inf;
        for(i=0;i<n;i++)
            if(distance[i]<mindistance && !visited[i]){
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;

        for(i=0;i<n;i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i]){
                    distance[i] = mindistance+cost[nextnode][i];
                    pred[i] = nextnode;
                }
        
        count++;
    }
    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            printf("\nDistance of node%d=%d",i,distance[i]);
            printf("\nPath=%d",i);
            
            j=i;
            do
            {
                j=pred[j];
                printf(" <-%d ",j);
            }while(j!=startnode);
        }
}