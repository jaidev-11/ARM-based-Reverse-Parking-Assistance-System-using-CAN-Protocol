typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short int u16;
typedef signed short int s16;

extern void delay_ms(unsigned int  ms);
extern void delay_sec(unsigned int sec);

extern void lcd_string (char *ptr);
extern void lcd_init(void);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_data(unsigned char data);

extern void uart0_init(unsigned int baud);
extern u8 uart0_rx(void);
extern void uart0_tx_string(u8 *ptr);
extern void uart0_rx_string(u8 *ptr,u8 len);
extern void uart0_tx_integer(int num);
extern void uart0_tx_float(float );
extern  void uart0_tx_octal(int );
extern void uart0_tx_hexadecimal(int );
//extern int uart0_my_atoi(char *) ;

extern u32 adc_read(u8 );
extern void add_init(void);
extern void EINT0_handler(void) __irq;
extern void config_vic_for_eint0(void);
extern void config_eint0(void);
extern void config_vic_for_uart0(void);
extern void en_uart0_interrupt(void);
extern void eint1_vic_config(void);
extern void cgram(void);

extern void i2c_init(void);
extern u8 i2c_byte_read_frame(u8, u8);
extern void i2c_byte_write_frame(u8 ,u8 ,u8 );
extern void uart0_tx_string(u8 *ptr);

typedef struct can1_msg
{
        u32 id;
        u32 rtr;
        u32 dlc;
        u32 byteA;
        u32 byteB;
}CAN1;

extern void can1_init(void);
extern void can1_tx(CAN1 );
extern void can1_rx(CAN1 * );
extern void en_can1_interupt(void);
extern void config_vic_for_can1(void);
extern void delay_us(u32 us);
extern void send_pulse(void);

extern void ultrasonic_init(void);
extern u32 get_range(void);
extern void config_vic_for_timer1(void);
extern void config_timer1(int t);
extern void eint0_vic_config(void);
