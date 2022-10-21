/* 
 * File:   sys_init.h
 * Author: sh70244
 *
 * Created on October 18, 2022, 12:41 PM
 */

#ifndef SYS_INIT_H
#define	SYS_INIT_H
#include <xc.h>
  void sys_init(void)
{
    GIE=1;//all control
    PEIE=1;
    RXB0IE=1;//enable interupt pin
    RXB0IP=1;//parity  enable
    
}

#endif	/* SYS_INIT_H */

