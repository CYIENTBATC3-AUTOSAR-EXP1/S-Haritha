/* 
 * File:   can_config.h
 * Author: sh70244
 *
 * Created on October 18, 2022, 11:12 AM
 */

#ifndef CAN_CONFIG_H
#define	CAN_CONFIG_H
#include <xc.h>
 void can_config_baud()
{
    set_mode(1);//call
   
        
            BRGCON1 = 0xC1;
            BRGCON2 = 0xAE;
            BRGCON3 = 0x45;
            set_mode(2);
    
} 
#endif	/* CAN_CONFIG_H */

