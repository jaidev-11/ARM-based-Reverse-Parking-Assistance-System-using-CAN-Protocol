#include<Lpc21xx.h>
#include"header.h"
#define THRE ((U0LSR>>5)&1)
#define RDR ((U0LSR>>0)&1)
void uart0_tx(unsigned char data)
{
        U0THR=data;
        while(THRE==0);
}
unsigned char uart0_rx()
{
        while(RDR==0);
        return U0RBR;
}
void uart0_init(unsigned int baud)
{
        char a[]={15,60,30,15,15};
        unsigned int pclk=0,result=0;
        pclk=a[VPBDIV%4]*1000000;
        result=pclk/(16*baud);
        PINSEL0 |=0X5;
        U0LCR=0X83;
        U0DLL= result &0xff;
        U0DLM= (result>>8)&0xff;
        U0LCR=0X03;
}
void uart0_tx_string(unsigned char  *ptr)
{
        while(*ptr)
 {
                U0THR=*ptr;
                while(THRE==0);
                ptr++;
 }
}
void uart0_tx_integer(int num)
{
                int a[10],i=0;
                if(num==0)
                uart0_tx(num+48);
                if(num<0)
                {
                        uart0_tx('-');
                        num=-num;
                }
                while(num)
                {
                        a[i++]=(num%10)+48;
                        num=num/10;
                }
                for(i=i-1; i>=0; i--)
                uart0_tx(a[i]);
}