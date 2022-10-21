/* 
 * File:   canif.h
 * Author: sh70244
 *
 * Created on October 20, 2022, 2:34 PM
 */
#include "xc.h"
#ifndef CANIF_H
#define	CANIF_H
//void canif(unsigned int, unsigned int);
/* 
 * File:   CAN_IF.h
 * Author: ma70436
 *
 * Created on October 19, 2022, 10:43 AM
 */

#ifndef CAN_IF_H
#define	CAN_IF_H

#include "pdurconfig.h"
#include "autosar_communicatconfig.h"

#ifdef	__cplusplus
extern "C" {
#endif

    const char Driver_Sel[4]={
        1,
        1,
        1,
        1
    }; 

//char CAN_IF(char Transmission_Type,char Buffer,int ID,char DLC,int Data);
//void Take_CAN_RX_Index(int ID,char DLC,char* Data);
void CAN_FRAME(PDUR_COM_MSg_list_E Msg_no,char* Data);

void   CAN_IF_Send_Msg(PDUR_COM_MSg_list_E Msg_no,int CAN_ID,char CAN_DLC,char* Data);


#ifdef	__cplusplus
}
#endif

#endif	/* CAN_IF_H */


#endif	/* CANIF_H */

