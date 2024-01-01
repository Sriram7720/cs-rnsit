#include<stdio.h>
#include<string.h>
#define N strlen(g)
int a,i,j;
char t[28],cs[28],g[] = "10001000000100001";

void xor(){
    for(j=1;j<N;j++)
        cs[j] = ((cs[j] == g[j])?'0':'1');
}

void crc(){
    for(i=0;i<N;i++){
        cs[i] = t[i];
    }
    do{
        if(cs[0] == '1')
            xor();
        for(j=0;j<N-1;j++)
            cs[j] = cs[j+1];
        cs[j] = t[i++];
    }while(i<=a+N-1);
}

void main(){
    printf("\n enter the data to be sent");
    scanf("%s",t);
    a = strlen(t);
    for(i=a;i<a+N-1;i++){
        t[i] = '0';
    }

    crc();
    printf("%s checksum \n\n",cs);

    for(i=a;i<a+N-1;i++) //data+checksum
        t[i]=cs[i-a];
    printf("%s codeword \n\n",t);

    printf("enter the recieved message \n");
    scanf("%s",t);

    crc();
    printf("remainder %s \n",cs);
    for(i=0;(i<N-1 && cs[i]!='1');i++);
    if(i<N-1)
        printf("\n\n error");
    else    
        printf("\n\nno error");
}