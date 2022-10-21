/* 
 * File:   TX_WRITE.h
 * Author: sh70244
 *
 * Created on October 18, 2022, 11:16 AM
 */
#ifndef TX_WRITE_H
#define	TX_WRITE_H
#include <xc.h>
        //transmission write data
        
       //set message IDs
void tx_write(unsigned int ID)
{
    set_mode(2);
    unsigned int DL=((ID <<5) & 0xFF);//size
    unsigned int DH= ((ID >>3) & 0xFF);
    TXB0SIDH = DH;//standared identifier data high
    TXB0SIDL =DL;//standared identifier data low
    
     TXB0DLC = 0x08; // 8 byte data of data in DLC
   TXB0D0 = 0x01;//sending data to the buffer 0......
   TXB0D1 = 0x02;
   TXB0D2 = 0x03;
   TXB0D3 = 0x04;
   TXB0D4 = 0x05;
   TXB0D5 = 0x06;
   TXB0D6  =0x07;
   TXB0D7 = 0x08;   
    
   TXB0CON = 0x08;  //normal mode  
}
/*CANCON=0x08;//normal mode
__Delay_ms(100);
    
TXB0CON=0x08;//

CANCON=0x08;//normal mode
__Delay_ms(100);
}      */  


#endif	/* TX_WRITE_H */

