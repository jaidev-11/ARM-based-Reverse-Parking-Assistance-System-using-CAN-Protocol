#include<lpc21xx.h>
#include "header.h"
extern u32 flag;
extern CAN1 m1;
void can1_rx_handler(void) __irq
{
        m1.id=C2RID;
        m1.dlc=(C2RFS>>16)&0XF;
        m1.rtr=(C2RFS>>30)&1;
        if(m1.rtr==0)
        {
                m1.byteA=C2RDA;
                m1.byteB=C2RDB;
        }
        C2CMR=(1<<2);
        flag=1;
        VICVectAddr=0;
}
void config_vic_for_can1(void)
{
        VICIntSelect=0;
        VICVectCntl2=27|(1<<5);
        VICVectAddr2=(u32) can1_rx_handler;
        VICIntEnable=(1<<27);
}