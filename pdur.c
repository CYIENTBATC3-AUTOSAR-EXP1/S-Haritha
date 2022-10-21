/*
 * File:   pdur.c
 * Author: sh70244
 *
 * Created on October 20, 2022, 3:25 PM
 */


#include <xc.h>
#include "pdur.h"




#include "candrv.h"
#include "pdurconfig.h"
#include "canif.h"
#include "autosar_communicatconfig.h"

/*
 *  This Function decides ID and Data to send msg
 *  "Frame_type" defines Standard Mode or Extended Mode
 *  "ID" define CAN IDentifier
 *  "DLC" Data Length Code
 *  "Data" defines Data to transmit
 * 
 */

void CAN_FRAME(PDUR_COM_MSg_list_E Msg_no,char Data[])
{
    switch(Msg_no)
    {
        case 0:
            CAN_IF_Send_Msg(Msg_no,PDUR_MSG_ID[Msg_no],PDUR_DLC[Msg_no],Data);
            break;
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }
}

//void CAN_FRAME(char Frame_type,char TRANS_Type,int ID,char DLC,char* Data)
//{
//    if(TRANS_Type)  /* CAN TX Type */
//    {
//        CAN_IF(TRANS_Type,Frame_type,ID,DLC,Data);
//        //Fill_CAN_TX_Buff(Frame_type,ID,DLC,Data); /* Calling API to Fill the data and decide ID */
//    }
//    else    /* CAN RX Type */
//    {
//        Take_CAN_RX_Index(ID,DLC,Data); /* Calling API to Receive CAN Data */
//    }
//}

