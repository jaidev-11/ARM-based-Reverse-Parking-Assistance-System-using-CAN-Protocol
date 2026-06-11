#include <LPC21XX.H>
#include "header.h"
void delay_sec( unsigned int sec)
{
        T0PC=0;
        T0PR=15000000-1;
        T0TC=0;
        T0TCR=1;
        while(T0TC<sec);
        T0TCR=0;
}
void delay_ms(unsigned int  ms)
{
        T0PC=0;
        T0PR=15000-1;
        T0TC=0;
        T0TCR=1;
        while(T0TC<ms);
        T0TCR=0;
}
void delay_us(unsigned int us)   //1us
{
        T1PC=0;
        T1TC=0;
        T1PR=59;
        T1TCR=0X02;//reset
        T1TCR=1;
        while(T1TC<us);
        T1TCR=0;
}
