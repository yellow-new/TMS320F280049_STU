/*
 * @Author: YellowNew
 * @Date: 2021-11-13 15:29:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2021-11-13 16:00:29
 * @FilePath: \TMS320F28004X\Source\BSW\HAL_Gpio.c
 * @Description: 
 * @Encoding: UTF-8
 */

#include "HAL_Gpio.h"


void BSW_InitGpio(void)
{
    GPIO_SetupPinMux(28, GPIO_MUX_CPU1, 1);
    GPIO_SetupPinOptions(28, GPIO_INPUT, GPIO_PUSHPULL);
    GPIO_SetupPinMux(29, GPIO_MUX_CPU1, 1);
    GPIO_SetupPinOptions(29, GPIO_OUTPUT, GPIO_ASYNC);
}
















