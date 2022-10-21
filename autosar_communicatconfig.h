/* 
 * File:   communicatconfig.h
 * Author: sh70244
 *
 * Created on October 21, 2022, 10:15 AM
 */

#ifndef AUTOSAR_COM_CONFIG_H
#define	AUTOSAR_COM_CONFIG_H


/* 
 * File:   AUTOSAR_COM_Config.h
 * Author: ma70436
 *
 * Created on October 20, 2022, 10:24 AM
 */

//#ifndef AUTOSAR_COM_CONFIG_H
//#define	AUTOSAR_COM_CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum COM_SIG_List{
    sig_1_e,
    sig_2_e,
    sig_3_e,
    sig_4_e,
    sig_5_e
}COM_SIG_e_List;

typedef struct MSg_1_s{
    unsigned int sig_1_s:8;
    unsigned int sig_2_s:8;
    unsigned int sig_3_s:8;
    unsigned int sig_4_s:8;
    unsigned int sig_5_s:8;
}AUTOSAR_MSG1;

typedef enum PDU_COM_MSg_list{
     MSg_1_s,
     Msg_2_s,
     Msg_3_s,
     Msg_4_s
}PDUR_COM_MSg_list_E;

extern AUTOSAR_MSG1 AUTOSAR_MSG1_S;
extern PDUR_COM_MSg_list_E;
extern COM_SIG_e_List;



void CAN_Send_signal(int CAN_SIG,int Value);



#endif	/* AUTOSAR_COM_CONFIG_H */




