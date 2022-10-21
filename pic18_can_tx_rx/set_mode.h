/* 
 * File:   setmode.h
 * Author: sh70244
 *
 * Created on October 18, 2022, 3:54 PM
 */

#ifndef SETMODE_H
#define	SETMODE_H
#include <xc.h>
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


#endif	/* SETMODE_H */

