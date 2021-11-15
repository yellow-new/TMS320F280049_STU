/*
 * @Author: YellowNew
 * @Date: 2021-11-13 15:29:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2021-11-15 20:07:12
 * @FilePath: \TMS320F28004X_GPIO\Source\BSW\HAL_Gpio.c
 * @Description: 
 * @Encoding: UTF-8
 */

#include "HAL_Gpio.h"


void BSW_InitGpio(void)
{
    GPIO_SetupPinMux(32 ,GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(32,GPIO_OUTPUT, GPIO_PUSHPULL);
}
















