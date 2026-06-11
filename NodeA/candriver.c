                   /*nodeA*/
#include<lpc21xx.h>
#include "header.h"
#define TCS (C2GSR&8)
#define RBS (C2GSR&1)
extern  CAN1 v;
void can1_init()
{
        VPBDIV=1;
        PINSEL1|=0X14000;
        C2MOD=1;
        AFMR=2;
        C2BTR=0X001C001D;
        //C2IER=1;
        C2MOD=0;
}


void can1_tx(CAN1 v)
{
        C2TID1=v.id;
        C2TFI1=(v.dlc<<16);//rtr=0,dlc=8,ff=0
        if(v.rtr==0)
        {
                C2TDA1=v.byteA;
                C2TDB1=v.byteB;
        }
        else
                C2TFI1|=(1<<30);
        C2CMR=1|(1<<5);//START TRASMISSION AND TXBUF1 SELETED
        while(TCS==0);
}
void can1_rx(CAN1 *r1)
{
        while(RRB==0);
        r1->id=C2RID;
        r1->dlc=(C2RFS>>16)&0XF;
        r1->rtr=(C2RFS>>30)&1;
        if(r1->rtr==0)
        {
                r1->byteA=C2RDA;
                r1->byteB=C2RDB;
        }
 	C2CMR=(1<<2);
}