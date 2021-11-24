/*
 * @Author: YellowNew
 * @Date: 2021-11-24 12:58:29
 * @LastEditTime: 2021-11-24 13:01:48
 * @Description: 
 * @FilePath: \TMS320F28004X_Adc\Source\ASW\ASW_Interrupt.h
 * @Encoding: UTF-8
 */

#ifndef _ASW_INTERRUPT_H_
#define _ASW_INTERRUPT_H_

#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"
#include "main.h"


#define RESULTS_BUFFER_SIZE     256
__interrupt void adcA1ISR(void);


#endif /*_ASW_INTERRUPT_H_*/


