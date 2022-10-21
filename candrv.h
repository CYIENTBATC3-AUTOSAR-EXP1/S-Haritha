/* 
 * File:   can.h
 * Author: sh70244
 *
 * Created on October 20, 2022, 2:34 PM
 */

//void candrv(unsigned int, unsigned int);
/* 
 * File:   CAN_Driver.h
 * Author: ma70436
 *
 * Created on October 18, 2022, 11:49 AM
 */

#include <xc.h>

#ifndef CAN_DRIVER_H
#define	CAN_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#define _XTAL_FREQ 20000000
    
#define NORMAL_MODE     0x00
#define CONFIG_MODE     0x80
#define DISABLE_MODE    0x20
#define LISEN_ONLY_MODE 0x60
#define LOOPBACK_MODE   0x40
    
#define Receive_Buffer0  0x0E
#define Receive_Buffer1  0x0A
#define Transmit_Buffer0 0x08
#define Transmit_Buffer1 0x06
#define Transmit_Buffer2 0x04
    
    
#define BAUD_RATE_125   125
#define BAUD_RATE_250   250    
#define BAUD_RATE_500   500
    

#define LED0 PORTBbits.RB0
#define LED1 PORTBbits.RB1

    
char CAN_Mode_Config(char MODE,char Buffer);
char CAN_Baud_rate_set(char BAUD_RATE);
void CAN_Init();
void sys_Init();
void Fill_CAN_TX_Buff(char Frame_type,int ID,char DLC,char* Data);



#ifdef	__cplusplus
}
#endif

#endif	/* CAN_DRIVER_H */


#endif	/* CAN_H */

