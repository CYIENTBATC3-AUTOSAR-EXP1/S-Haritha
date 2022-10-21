/* 
 * File:   mask_filter.h
 * Author: sh70244
 *
 * Created on October 20, 2022, 12:51 PM
 */

#ifndef MASK_FILTER_H
#define	MASK_FILTER_H
#include <xc.h>
void mask_filter()
{
    RXF0SIDH=0x00;
    RXF0SIDL=0x00;
    RXM0SIDH=0x00;
    RXM0SIDL=0x00;
   // CIOCON=0X20;
}

#endif	/* MASK_FILTER_H */

