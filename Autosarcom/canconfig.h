/* 
 * File:   canconfig.h
 * Author: sh70244
 *
 * Created on October 20, 2022, 3:11 PM
 */
#include "xc.h"
#ifndef CANCONFIG_H
#define	CANCONFIG_H

void can_config_baud()
{
    set_mode(1);//call
   
        
            BRGCON1 = 0xC1;
            BRGCON2 = 0xAE;
            BRGCON3 = 0x45;
           set_mode(2);
    
} 

#endif	/* CANCONFIG_H */

