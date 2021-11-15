/*
 * @Author: YellowNew
 * @Date: 2021-11-15 19:43:28
 * @LastEditors: Do not edit
 * @LastEditTime: 2021-11-15 19:57:35
 * @FilePath: \TMS320F28004X_GPIO\Source\ASW\ASW_LED.h
 * @Description: 
 * @Encoding: UTF-8
 */


#ifndef _ASW_LED_H_
#define _ASW_LED_H_

#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"



#define LED_ON()   (GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1)


#define LED_OFF()  (GpioDataRegs.GPBSET.bit.GPIO32 = 1)

#endif // _ASW_LED_H_



