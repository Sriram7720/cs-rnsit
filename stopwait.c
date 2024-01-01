#include<stdio.h>
#include<stdlib.h>

#define RTT 4
#define TOT_frames 7
#define tm 4

enum {yes,no} ACK;

void main(){
    int i = 1,wt;
    ACK = yes;
    while(i<=TOT_frames){
        if(ACK == yes && i!=1){
            printf("\n SENDER : ack recieved for frame %d",i-1);
            printf("\n\n------------------------------------------------");
        }
        printf("\n SENDER : frame %d is sent waiting for ack",i);
        wt = rand()%4+1;
        ACK = no;
        if(wt == tm){
            printf("\n SENDER : ack not recieved resending the frame");
        }
        else{
            //sleep(RTT);
            printf("\n RECIEVER : frame %d recieved ack sent",i);
            ACK = yes;
            i++;
        }
    }
}