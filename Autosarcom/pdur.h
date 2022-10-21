/* 
 * File:   pdur.h
 * Author: sh70244
 *
 * Created on October 20, 2022, 2:34 PM
 */
#include <xc.h>
#include<stdio.h>
#ifndef PDUR_H
#define	PDUR_H

void pdur(unsigned int,unsigned int unsigned char);

typedef struct 
{
    int id;
    int dlc;
    char protocol;
}pdur_para_struct;

int pdur_para_struct[2]={100,8,'CAN',200,8,'lin',300,8,'spl'};
//char pdur_para_struct[2]={'CAN','LIN'};

#endif	/* PDUR_H */

