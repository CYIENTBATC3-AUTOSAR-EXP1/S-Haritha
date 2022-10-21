/* 
 * File:   cansetmode.h
 * Author: sh70244
 *
 * Created on October 20, 2022, 3:54 PM
 */
#include "xc.h"
#ifndef CANSETMODE_H
#define	CANSETMODE_H
void set_mode(unsigned int X)
{
    if(X == 1)
        CANCON = 0x80;// set configuration mode
    else if(X == 2)
        CANCON = 0x08;//normal mode TX buffer 0
     else if(X == 3)
        CANCON = 0x0E;//normal mode RX buffer 0
    else ;
}



#endif	/* CANSETMODE_H */

