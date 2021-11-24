/*
 * @Author: YellowNew
 * @Date: 2021-11-12 21:32:07
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-11-24 13:01:42
 * @FilePath: \TMS320F28004X_Adc\Source\ASW\main.c
 * @Description: 
 * @Encoding: UTF-8
 */
#include "main.h"

#if 1
void main()
{
    //
    // 系统初始化
    //
    BSW_InitSystem();

    //
    // Gpio初始化
    //
    BSW_InitGpio();

    //
    // ADC基本配置初始化
    //
    BSW_ConfigureADC();

    //
    // ADC触发初始化
    //
    BSW_initADCSOCtoEPMW();



    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
    EINT;
    ERTM;

     for(;;)
     {

     }

}







#else

void main(void)
{
    //
    // Initializes system control, device clock, and peripherals
    //
    Device_init();

    //
    // Initializes PIE and clear PIE registers. Disables CPU interrupts.
    // and clear all CPU interrupt flags.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    while(1);

}

#endif


