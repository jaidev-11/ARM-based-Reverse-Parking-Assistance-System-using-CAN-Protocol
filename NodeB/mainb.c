#include <lpc21xx.h>
#include "header.h"
CAN1 m1,m2;
u32 flag;
int main()
{
        u32 d1,r;
        can1_init();
        config_vic_for_can1();
        ultrasonic();
        uart0_init(9600);
        while(1)
        {
                if(flag==1)
                {
                        flag=0;
                        uart0_tx_string("remote frame is received\r\n");
                        if(m1.rtr==1)
                        {
                                r=1;
                                m2.dlc=m1.dlc;
                                m2.id=m1.id;
                        }
                        else
                        r=0;
                }
                if(r==1)
                {
                        d1=distance();
                        delay_ms(50);
                        uart0_tx_integer(d1);
                        m2.byteA=d1;
                        m2.rtr=0;
                        uart0_tx_string("response to remote frame\r\n");
                        can1_tx(m2);
                }
        }

}