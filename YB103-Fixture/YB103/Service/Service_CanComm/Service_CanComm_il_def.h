/*
 * Service_CanComm_il_def.h
 *
 *  Created on: 2025��1��8��
 *      Author: user
 */

#ifndef APP_CAN_IL_DEF_H_
#define APP_CAN_IL_DEF_H_


#define iTxIsIdle           (uint8_t)0x00
#define iTxIsWait           (uint8_t)0x01
#define iTxIsRun            (uint8_t)0x02
#define iRxIsWait           (uint8_t)0x04
#define iRxIsRun            (uint8_t)0x08

#define iTxIsNotWait        (uint8_t)0xfe
#define iTxIsNotRun         (uint8_t)0xfd
#define iRxIsNotWait        (uint8_t)0xfb
#define iRxIsNotRun         (uint8_t)0xf7

#define iCanNotUsedTxHandle ((uint16_t) 0xFFFFFFFF)

#define iStopUpdateCntVal   ((uint8_t)0xFFFFu)


#define iTxQuickStart       (uint8_t)0x10
#define iTxReqSend          (uint8_t)0x80

#define iNotTxReq           (uint8_t)0x7f

#endif /* APP_CAN_IL_DEF_H_ */
