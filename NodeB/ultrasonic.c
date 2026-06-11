#include <LPC21xx.H>
#include"header.h"
#define TRIG (1<<10)
#define ECHO (1<<11)
void ultrasonic(void)
{
        IODIR0 |= TRIG;
        IODIR0 &= ~(ECHO);
        T0TCR = 0x02;
//      T0PR = 59;
//      T0TCR = 1;

}
unsigned int distance(void)
{
        unsigned int dist, time;
        T0TC = 0;
        T0PC = 0;
        T0PR = 59;
        T0TCR = 0x02;
        //IOCLR0 = 1<<10
        IOCLR0 = 1<<11;
        delay_us(2);
        IOSET0 = 1<<11;
        delay_us(10);
        IOCLR0 = 1<<11;

        while(!(IOPIN0 & 1 << 10));
        T0TCR = 1;
        while(IOPIN0 & 1 << 10);
        T0TCR = 0;
        time = T0TC;
        dist = (0.0343*time)/2;
        return dist;
}