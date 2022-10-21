/* 
 * File:   rx_receive.h
 * Author: sh70244
 *
 * Created on October 18, 2022, 3:37 PM
 */

#ifndef RX_RECEIVE_H
#define	RX_RECEIVE_H
#include <xc.h>
unsigned int DHR;
unsigned int DLR;
unsigned int DLCR;
unsigned int RX_data[8];

void rx_receive() //receiving data from TX 
{
    
    set_mode(3);
    DHR=RXB0SIDH;
    DLR=RXB0SIDL;
    
    DLCR=RXB0DLC;//data  length code receiver 8bytes data.
    RX_data[0]=RXB0D0; //the data receiving from tx is given to rx by 
    RX_data[1]=RXB0D1;
    RX_data[2]=RXB0D2;
    RX_data[3]=RXB0D3;
    RX_data[4]=RXB0D4;
    RX_data[5]=RXB0D5;
    RX_data[6]=RXB0D6;
    RX_data[7]=RXB0D7;
    RXB0CONbits.RXB0FUL=0;//clear rx bits
    
    
    //RXFUL=0;//8bytes of data
}

#endif	/* RX_RECEIVE_H */

