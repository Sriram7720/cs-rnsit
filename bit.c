#include<stdio.h>

void main(){
    int a[20],b[30],i,j,k,n,count;
    printf("enter the frame length \n");
    scanf("%d",&n);
    printf("enter the frame \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    count = 0;
    j=0;
    for(i=0;i<n;i++){
        if(a[i]==1){
            count++;
            printf("%d \n",count);
            if(count == 6){
                b[j] = 0;
                j++;
                b[j] = a[i];
                count = 0;
            } 
            else
                b[j] = a[i];
        }
        else
            b[j] = a[i];
        j++;
    }
    printf("stuffed \n");
    printf("01111110_");
    for(i=0;i<j;i++)
        printf("%d",b[i]);
    printf("_01111110");
}