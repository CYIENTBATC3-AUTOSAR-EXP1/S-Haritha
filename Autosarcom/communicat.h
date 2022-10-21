/* 
 * File:   mcal.h
 * Author: sh70244
 *
 * Created on October 20, 2022, 12:59 PM
 */
#include <xc.h>


void communication(unsigned int sig_new,unsigned int msg_list,unsigned int msg1_struct);
extern msg1_struct;

typedef enum
{
     sig_speed,
     sig_temp,
     sig_max_value
}sig_list;

typedef enum 
{
   msg1,
   msg2,
   msg_max_value,
}msg_list;

typedef struct
{
  int sig_speed:8;
  int sig_temp:8;  
}msg1_struct;



