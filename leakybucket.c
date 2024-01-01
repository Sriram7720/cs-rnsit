#include<stdio.h>
#include<stdlib.h>
#define n 5
#define bucket_s 500

void buck(int *bucket, int op){
    if(*bucket > 0 && *bucket > op){
        *bucket = *bucket - op;
        printf("\n remaining in bucket is %d \n",*bucket);
    }
    else if(*bucket >0){
        printf("\n outputted %d from bucket \n",*bucket);
        *bucket = 0;
    }
}

void main(){
    int i,bucket,wt,op,oldpack=0,j,newpack;
    printf("\n enter op ");
    scanf("%d",&op);
    for(i=1;i<=n;i++){
            newpack = rand()%300;
            newpack = oldpack+newpack;
            wt = rand()%5;
            if(newpack < bucket_s){
                bucket = newpack;
            }
            else{
                printf("\n newpack is > bucket_size rejected\n");
                bucket = oldpack;
            }
        
        printf("data in the bucket %d \n",bucket);
        printf("wait time generated %d \n",wt);
        for(j=0;j<wt;j++){
            buck(&bucket,op);
        }
        oldpack = bucket;
        
    }
    while(bucket>0){
            buck(&bucket,op);
        }
}