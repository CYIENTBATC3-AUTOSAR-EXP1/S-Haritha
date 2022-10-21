/* 
 * File:   can.h
 * Author: sh70244
 *
 * Created on October 18, 2022, 11:08 AM
 */

#ifndef CAN_H
#define	CAN_H
  #include <xc.h>
    void can_init(void)
{
    TRISBbits.RB2=0;//TX bits
    TRISBbits.RB3=1;//RX
    TRISBbits.RB7=0;//RX
    TRISBbits.RB6=0;//RX
}
#endif /*can init*/