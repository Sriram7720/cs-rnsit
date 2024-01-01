#include<stdio.h>
#include<string.h>

void main(){
    char a[30],b[30],i=0,j=0,n;
    printf("\n enter the sting\n");
    scanf("%s",&a);
    n = strlen(a);
    b[j] = 'd';
    b[j+1] = 'l';
    b[j+2] = 'e';
    b[j+3] = 's';
    b[j+4] = 't';
    b[j+5] = 'x';
    j = 6;
    while(i<n){
        if(a[i] == 'd' && a[i+1] == 'l' && a[i+2]){
            b[j] = 'd';
            b[j+1] = 'l';
            b[j+2] = 'e';
            j = j+3;
        }
        b[j] = a[i];
        i++;
        j++;
    }
    b[j] = 'd';
    b[j+1] = 'l';
    b[j+2] = 'e';
    b[j+3] = 's';
    b[j+4] = 't';
    b[j+5] = 'x';
    b[j+6] = '\0';
    printf("stuffed \n");
    printf("%s",b);

}