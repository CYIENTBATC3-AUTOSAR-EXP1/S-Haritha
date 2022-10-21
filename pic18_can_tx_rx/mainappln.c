/*
 * File:   TXRX.c
 * Author: sh70244
 *
 * Created on October 18, 2022, 10:01 AM
 */
// PIC18F4585 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = BOHW     // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (VBOR set to 2.1V)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = OFF      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR disabled)

// CONFIG4L
#pragma config STVREN = OFF     // Stack Full/Underflow Reset Enable bit (Stack full/underflow will not cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config BBSIZ = 1024     // Boot Block Size Select bits (1K words (2K bytes) Boot Block)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-003FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (004000-007FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (008000-00BFFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-003FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (004000-007FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (008000-00BFFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>
#define _XTAL_FREQ 20000000


#include "sys_init.h"
#include "can_init.h"
#include "set_mode.h"
#include "can_config.h"
#include "TX_WRITE.h"
#include "RX_receive.h"
#include "mask_filter.h"



void tx_write(unsigned int ID);
void rx_receive();
void mask_filter();

int flag=0;

  
void __interrupt() ISR1()
{
    PORTBbits.RB7=1;
    if(RXB0IF == 1)
    {
      
        RXB0IF = 0;
        flag=1;//FLAG
              
    }
    
}

void main(void) 
{
    TRISBbits.RB0=0;//output
    TRISCbits.RC0=1;//input
    sys_init();//system initialisation
    can_init();//can initialisation
    can_config_baud();//baudrate configurations
    mask_filter();
    //DHR=RXB0SIDH;
    //DLR=RXB0SIDL;
    //unsigned int RXB0DHR;
    //unsigned int RXB0DLR;
    while(1)
    {
    tx_write(0x100);//0X100 is an ID means PDUR.h 
    __delay_ms(1000);
    if(flag==1)
    {
        flag=0;
    rx_receive();
  if((DHR == 0X00) && (DLR== 0X40))//after receiving RX data chechking the data receving correct or not
  {
    if(RX_data[0]&0X01)
    {
        PORTBbits.RB7=0;
        PORTBbits.RB6=1;
    }
   else
   {
      PORTBbits.RB6=0; 
   }
    }
    }
    __delay_ms(1000);
   
  
    }    
    return;
}
/*
* CAN_Send_msg is used to transmit the data on the bus
* attributes "type" define mode of bus
*  1 - Standard mode
*  0 - Extended mode
* "DLC" defines Data Length Code
* "ID" is nothing but Identifier
*/


